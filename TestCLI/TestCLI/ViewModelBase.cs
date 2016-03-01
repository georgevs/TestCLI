using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace TestCLI
{
    public class ViewModelBase : INotifyPropertyChanged
    {
        // INotifyPropertyChanged...
        public event PropertyChangedEventHandler PropertyChanged;
        
        // generic set property template
        protected virtual bool setProperty<T>(ref T storage, T value,
                            [CallerMemberName] string propertyName = null)
        {
            if ((storage == null && value == null) || 
                (storage != null && storage.Equals(value))) {
                return false; // nothing to do; property has not been changed
            }
            
            storage = value;
            
            var handler = PropertyChanged;
            if (handler != null)
            {
                handler(this, new PropertyChangedEventArgs(propertyName));
            }
            return true; // property has been changed
        }
    }

    public class DelegateCommand<T> : ICommand
    {
        public event EventHandler CanExecuteChanged;

        public DelegateCommand(Action<T> executeMethod, Predicate<T> canExecuteMethod)
        {
            executeMethod_ = executeMethod;
            canExecuteMethod_ = canExecuteMethod;
        }
        public bool CanExecute(object param)
        {
            if (canExecuteMethod_ == null) return true;
            return canExecuteMethod_((T)param);
        }
        public void Execute(object param)
        {
            if (executeMethod_ == null) return;
            executeMethod_((T)param);
        }
        public void NotifyCanExecuteChanged() {
            if (CanExecuteChanged != null) {
                CanExecuteChanged(this, EventArgs.Empty);
            }
        }

        private Action<T> executeMethod_;
        private Predicate<T> canExecuteMethod_;
    }
}
