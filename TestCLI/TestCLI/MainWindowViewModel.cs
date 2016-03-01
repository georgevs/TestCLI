using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ClassLibrary1;

namespace TestCLI
{
    public class MainWindowViewModel : ViewModelBase
    {
        public MainWindowViewModel()
        {
            HelloWorldCommand = new DelegateCommand<object>((param) => HelloWorld(), (param) => true);
            Model = ModelFactory.CreateModel();
        }

        public DelegateCommand<object> HelloWorldCommand { get; private set; }

        private void HelloWorld()
        {
            Model.HelloWorld();
        }

        public IModel Model { get; private set; }
    }
}
