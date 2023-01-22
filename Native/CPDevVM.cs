using BlazorVM.Pages;
using System.Globalization;
using System.Reflection.PortableExecutable;
using System.Runtime.InteropServices;

namespace BlazorVM.Native
{

    public class CPDevVM
    {

        [DllImport("test")]
        static extern int CPDev_Init();

        [DllImport("test")]
        static extern int CPDev_RunCycle();

        [DllImport("test")]
        static extern int CPDev_LoadProgram(byte[] data, int length);

        [DllImport("test")]
        static extern byte CPDev_GetBool(int adr);
        [DllImport("test")]
        static extern byte GetDataByte(uint address);
        [DllImport("test")]
        static extern UInt16 GetDataWord(uint address);
        [DllImport("test")]
        static extern UInt32 GetDataDWord(uint address);
        [DllImport("test")]
        static extern UInt64 GetDataLWord(uint address);
        [DllImport("test")]
        static extern float GetDataReal(uint address);
        [DllImport("test")]
        static extern double GetDataLReal(uint address);

        [DllImport("test")]
        static extern int GetData(uint src_address, uint length, byte[] buffer);

        [DllImport("test")]
        static extern int SetData(uint src_address, uint length, byte[] buffer);

        IntPtr vm = IntPtr.Zero;

        public bool Valid { get; set; } = false;

        public bool Modified { get; private set; } = false;

        public bool IsRunning { get; private set; } = false;


        List<CPDevVariable> variables = new List<CPDevVariable>();
        public List<CPDevVariable> Variables { get { return variables; } }


        public CPDevVM()
        {
            CPDev_Init();
        }

        public bool LoadProgram(byte[] xcpdata)
        {
            if (CPDev_LoadProgram(xcpdata, xcpdata.Length) == 0)
            {
                Valid = true;
                return true;
            }

            return false;
        }

        public int RunCycle()
        {
            int res = CPDev_RunCycle();

            foreach (var v in Variables)
            {
                GetData(v);
            }

            return res;
        }

        public void Close()
        {
            Valid = false;
            Modified = false;
        }

        public bool GetData(CPDevVariable v)
        {
            switch (v.Type)
            {
                case "BOOL":
                    v.Value = GetDataByte(v.Address).ToString();
                    break;
                case "BYTE":
                case "USINT":
                    v.Value = GetDataByte(v.Address).ToString();
                    break;
                case "SINT":
                    v.Value = ((sbyte)(GetDataByte(v.Address))).ToString();
                    break;
                case "INT":
                    Int16 val = (Int16)(GetDataWord(v.Address));
                    v.Value = val.ToString();
                    break;
                case "WORD":
                case "UINT":
                    v.Value = (GetDataWord(v.Address)).ToString();
                    break;
                case "DWORD":
                case "UDINT":
                case "TIME":
                case "TIME_OF_DAY":
                case "DATE":
                    v.Value = (GetDataDWord(v.Address)).ToString();
                    break;
                case "DINT":
                case "FINT":
                    v.Value = ((Int32)GetDataDWord(v.Address)).ToString();
                    break;
                case "LWORD":
                case "ULINT":
                case "DATE_AND_TIME":
                    v.Value = (GetDataLWord(v.Address)).ToString();
                    break;
                case "LINT":
                    v.Value = ((long)GetDataLWord(v.Address)).ToString();
                    break;
                case "REAL":
                    NumberFormatInfo fi = new NumberFormatInfo();
                    fi.NumberDecimalDigits = 6;
                    v.Value = GetDataReal(v.Address).ToString(fi);
                    break;
                case "LREAL":
                    v.Value = GetDataLReal(v.Address).ToString(NumberFormatInfo.InvariantInfo);
                    break;
                case "STRING":
                    v.Value = GetDataString(v.Address);
                    break;
                default:
                    return false;
            }

            return true;


        }

        public string GetDataString(uint addr)
        {
            int len = GetDataByte(addr);
            uint padding = GetDataWord(addr + 2);
            int charSize = 1;
            if ((padding & 0x1) != 0)  // WSTRING
                charSize++;

            byte[] buffer = new byte[len * charSize];
            GetData(addr + 4, (uint)(len * charSize), buffer);

            if (charSize == 1)
                return System.Text.Encoding.Default.GetString(buffer as byte[], 0, len * charSize);
            else
                return System.Text.Encoding.Unicode.GetString(buffer as byte[], 0, len * charSize);

        }

        public void SetDataByte(uint addr, byte val)
        {
            byte[] num = new byte[1];
            num[0] = val;

            SetData(addr, num);

            return;
        }

        public void SetDataWord(uint addr, UInt16 val)
        {
            byte[] b = BitConverter.GetBytes(val);
            SetData(addr, b);

            return;
        }

        public void SetDataDWord(uint addr, UInt32 val)
        {
            byte[] b = BitConverter.GetBytes(val);
            SetData(addr, b);

            return;
        }

        public void SetDataLWord(uint addr, UInt64 val)
        {
            byte[] b = BitConverter.GetBytes(val);
            SetData(addr, b);

            return;
        }

        public void SetDataReal(uint addr, float val)
        {
            byte[] b = BitConverter.GetBytes(val);
            SetData(addr, b);

            return;
        }

        public void SetDataLReal(uint addr, double val)
        {
            byte[] b = BitConverter.GetBytes(val);
            SetData(addr, b);

            return;
        }

        public void SetDataString(uint addr, string data)
        {
            byte[] buffer = System.Text.Encoding.ASCII.GetBytes(data);
            uint len = (uint)buffer.Length;
            if (len > 252) len = 252;
            uint maxlen = GetDataByte(addr + 1);
            if (len > maxlen) len = maxlen;
            SetDataByte(addr, (byte)len);
            SetData((uint)(addr + 4), buffer);
        }


        public void SetData(uint addr, byte[] b)
        {
            SetData(addr, (uint)b.Length, b);
        }

        public bool SetData(CPDevVariable v)
        {
            try
            {
                switch (v.Type)
                {
                    case "BOOL":
                    case "BYTE":
                    case "USINT":
                        SetDataByte(v.Address, byte.Parse(v.Value));
                        break;
                    case "SINT":
                        SetDataByte(v.Address, (byte)sbyte.Parse(v.Value));
                        break;
                    case "INT":
                        SetDataWord(v.Address, (UInt16)Int16.Parse(v.Value));
                        break;
                    case "WORD":
                    case "UINT":
                        SetDataWord(v.Address, UInt16.Parse(v.Value));
                        break;
                    case "DWORD":
                    case "UDINT":
                    case "TIME":
                    case "TIME_OF_DAY":
                    case "DATE":
                        SetDataDWord(v.Address, UInt32.Parse(v.Value));
                        break;
                    case "DINT":
                    case "FINT":
                        SetDataDWord(v.Address, (UInt32)Int32.Parse(v.Value));
                        break;
                    case "LWORD":
                    case "ULINT":
                    case "DATE_AND_TIME":
                        SetDataLWord(v.Address, UInt64.Parse(v.Value));
                        break;
                    case "LINT":
                        SetDataLWord(v.Address, (UInt32)Int64.Parse(v.Value));
                        break;
                    case "REAL":
                        SetDataReal(v.Address, float.Parse(v.Value, NumberFormatInfo.InvariantInfo));
                        break;
                    case "LREAL":
                        SetDataLReal(v.Address, double.Parse(v.Value, NumberFormatInfo.InvariantInfo));
                        break;
                    case "STRING":
                    case "WSTRING":
                        SetDataString(v.Address, v.Value);
                        break;
                    default:
                        return false;
                }

                return true;
            }
            catch
            {
                return false;
            }
            finally
            {

            }
        }


    }

    public class CPDevVariable
    {
        public string Name { get; set; }
        public string Value { get; set; }
        public uint Address { get; set; }

        public string Type { get; set; }
        public int Size { get; set; } = 1;

    }
}
