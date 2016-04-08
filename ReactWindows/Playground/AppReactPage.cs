using Newtonsoft.Json.Linq;
using ReactNative;
using ReactNative.Bridge;
using ReactNative.Modules.Core;
using ReactNative.Shell;
using ReactNative.UIManager;
using System;
using System.Collections.Generic;
using Windows.UI.Core;
using Windows.UI.Xaml;

namespace Playground
{
    class AppReactPage : ReactPage
    {
        public override string MainComponentName
        {
            get
            {
                return "Game2048";
            }
        }

        public override string JavaScriptMainModuleName
        {
            get
            {
                return "Examples/2048/Game2048";
            }
        }

#if BUNDLE
        public override string JavaScriptBundleFile
        {
            get
            {
                return "ms-appx:///ReactAssets/index.windows.bundle";
            }
        }
#endif

        public override List<IReactPackage> Packages
        {
            get
            {
                return new List<IReactPackage>
                {
                    new MainReactPackage(),
                    new AppReactPackage(),
                };
            }
        }

        public override bool UseDeveloperSupport
        {
            get
            {
#if DEBUG
                return true;
#else
                return false;
#endif
            }
        }

        class AppReactPackage : IReactPackage
        {
            public IReadOnlyList<Type> CreateJavaScriptModulesConfig()
            {
                return Array.Empty<Type>();
            }

            public IReadOnlyList<INativeModule> CreateNativeModules(ReactContext reactContext)
            {
                return new List<INativeModule>
                {
                    new KeyListenerModule(reactContext),
                };
            }

            public IReadOnlyList<IViewManager> CreateViewManagers(ReactContext reactContext)
            {
                return Array.Empty<IViewManager>();
            }

            class KeyListenerModule : ReactContextNativeModuleBase
            {
                public KeyListenerModule(ReactContext context)
                    : base(context)
                {
                }

                public override void Initialize()
                {
                    Window.Current.CoreWindow.KeyUp += OnKeyUp;
                    Window.Current.CoreWindow.KeyDown += OnKeyDown;
                }

                public override string Name
                {
                    get
                    {
                        return "KeyListenerWindows";
                    }
                }

                private void OnKeyDown(CoreWindow sender, KeyEventArgs e)
                {
                    var data = new JObject
                    {
                        { "key", e.VirtualKey.ToString() },
                    };

                    Context.GetJavaScriptModule<RCTDeviceEventEmitter>().emit("keyDown", data);
                }

                private void OnKeyUp(CoreWindow sender, KeyEventArgs e)
                {
                    var data = new JObject
                    {
                        { "key", e.VirtualKey.ToString() },
                    };

                    Context.GetJavaScriptModule<RCTDeviceEventEmitter>() .emit("keyUp", data);
                }
            }
        }
    }
}
