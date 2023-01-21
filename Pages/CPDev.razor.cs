using BlazorVM.Native;
using Microsoft.AspNetCore.Components.Forms;
using Microsoft.AspNetCore.Components.Routing;
using Microsoft.JSInterop;
using MudBlazor;
using System.Net.NetworkInformation;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Text;
using System.Timers;
using System.Xml.Linq;
using System.Xml.XPath;
using static MudBlazor.CategoryTypes;
using static MudBlazor.Colors;

namespace BlazorVM.Pages
{
    public partial class CPDev
    {
        CPDevVM CPDevVM = new CPDevVM();
        string fileName;

        bool Loading { get; set; }

        private HashSet<CPDevVariable> selectedItems = new HashSet<CPDevVariable>();

        string searchName = string.Empty;

        bool IsSaved { get; set; }

        bool IsRunning { get { return timer == null ? false : timer.Enabled; } }

        private MudTable<CPDevVariable>? mudTable;

        private System.Timers.Timer timer = new System.Timers.Timer();

        protected override void OnInitialized()
        {
            Navigation.LocationChanged += Navigation_LocationChangedAsync;
            timer.Elapsed += RunCycle;
        }

        async Task OnFileChanged(InputFileChangeEventArgs e)
        {
            try
            {
                bool dcpLoaded = false;

                Loading = true;

                foreach (var file in e.GetMultipleFiles(e.FileCount))
                {
                    if (file.Name.EndsWith(".xcp"))
                    {
                        await LoadXCP(file);
                    }

                    if (file.Name.EndsWith(".dcp"))
                    {
                        await LoadDCP(file);
                        dcpLoaded = true;
                    }
                }

                if (!dcpLoaded)
                {
                    Snackbar.Add("Cannot open the files. Have you selected valid CPDev files (XCP and DCP) ?", Severity.Error);
                }

            }
            catch (Exception ex)
            {
                Snackbar.Add("Cannot open the file. Is this a valid CPDev file ?", Severity.Error);
            }
            finally
            {
                Loading = false;
            }
        }

        private async Task LoadXCP(IBrowserFile file)
        {
            var fileData = new byte[file.Size];

            fileName = file.Name;

            await file.OpenReadStream().ReadAsync(fileData);
            await Task.Delay(1);

            //message = null;
            if (CPDevVM.LoadProgram(fileData))
            {
                //currentCount = CPDevVM.FileCount;
                //this.StateHasChanged();

                IsSaved = false;
            }
            else
            {
                Snackbar.Add("Cannot open the file. Is this a valid XCP ?", Severity.Error);
            }
        }

        private async Task LoadDCP(IBrowserFile file)
        {
            var fileData = new byte[file.Size];

            CPDevVM.Variables.Clear();

            try
            {
                MemoryStream ms = new MemoryStream();
                await file.OpenReadStream().CopyToAsync(ms);
                await Task.Delay(1);

                ms.Seek(0, SeekOrigin.Begin);

                XDocument xdcp = XDocument.Load(ms);
                var globals = xdcp.XPathSelectElements("/CPDEV/TARGET/GLOBAL/VAR");
                foreach (var g in globals)
                {
                    CPDevVariable var = new CPDevVariable();

                    var.Name = g.Attribute("LName")!.Value;
                    var.Address = uint.Parse(g.Attribute("Addr")!.Value);
                    var.Size = int.Parse(g.Attribute("Size")!.Value);
                    var.Type = g.Attribute("Type")!.Value;

                    CPDevVM.Variables.Add(var);
                }
            }
            catch(Exception ex)
            {
                Snackbar.Add("Cannot open the file. Is this a valid DCP ?", Severity.Error);
            }
        }

        private async void Navigation_LocationChangedAsync(object? sender, LocationChangedEventArgs e)
        {
            //await CloseImage();
        }

        private async Task CloseImage()
        {
            if (CPDevVM.Valid && CPDevVM.Modified && !IsSaved)
            {

                bool? result = await DialogService.ShowMessageBox(
         $"Warning",
         "Do you want to save the changes ?",
         yesText: "Save", cancelText: "Cancel");

                if (result != null)
                {
                    //await SaveRom();
                }
            }

            CPDevVM.Close();

            Navigation.LocationChanged -= Navigation_LocationChangedAsync;
        }


        private bool FilterName(CPDevVariable element)
        {
            if (string.IsNullOrWhiteSpace(searchName))
                return true;
            if (element.Name.Contains(searchName, StringComparison.OrdinalIgnoreCase))
                return true;
            return false;
        }

        private void StartVM()
        {
            if (CPDevVM.Valid)
            {
                timer.Interval = 500;
                timer.Enabled = true;
            }
        }

        private void StopVM()
        {
            if (CPDevVM.Valid)
            {
                timer.Enabled = false;
            }
        }

        private void RunCycle(object? sender, ElapsedEventArgs e)
        {
            CPDevVM.RunCycle();
            StateHasChanged();
        }

        private CPDevVariable elementBeforeEdit;

        private void BackupItem(object element)
        {
            timer.Enabled = false;
            elementBeforeEdit = new()
            {
                Name = ((CPDevVariable)element).Name,
                Value = ((CPDevVariable)element).Value,
            };
            //AddEditionEvent($"RowEditPreview event: made a backup of Element {((Element)element).Name}");
        }

        private void ItemHasBeenCommitted(object element)
        {
            //AddEditionEvent($"RowEditCommit event: Changes to Element {((Element)element).Name} committed");
            CPDevVM.SetData((CPDevVariable)element);
            timer.Enabled = true;
        }

        private void ResetItemToOriginalValues(object element)
        {
            ((CPDevVariable)element).Name = elementBeforeEdit.Name;
            ((CPDevVariable)element).Value = elementBeforeEdit.Value;
        }
    }
}