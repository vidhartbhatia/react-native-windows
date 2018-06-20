// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

using System;

namespace ReactNative.Modules.Core
{
    public interface IMutableFrameEventArgs
    {
        void Update(TimeSpan renderingTime);
    }
}
