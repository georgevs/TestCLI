// ClassLibrary1.h

#pragma once

#include "Win32Project1\Win32Project1.h"

using namespace System;

namespace ClassLibrary1 {

    public enum class EState {
        eStateOne = Win32Project1::EState::eStateOne,
        eStateTwo = Win32Project1::EState::eStateTwo,
        eStateThree = Win32Project1::EState::eStateThree
    };

    public interface class IModel
    {
        void HelloWorld();
        property EState State {
            EState get();
            void set(EState value);
        }
    };

    ref class Model : IModel
    {
    public:
        Model() 
            :   _model(CreateModel()) {
        }
        ~Model() {   // Dispose()
            this->!Model();
        }
        !Model() {    // Finalize()
            delete _model;
        }
        virtual void HelloWorld() {
            _model->HelloWorld();
        }
        property EState State {
            virtual EState get() {
                return EState(_model->state());
            }
            virtual void set(EState value) {
                _model->setState(Win32Project1::EState(value));
            }
        }
    private:
        Win32Project1::IModel* _model;
    };
    
    public ref class ModelFactory 
    {
    public:
        static IModel^ CreateModel() {
            return gcnew Model();
        }
    };

}
