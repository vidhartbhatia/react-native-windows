// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

namespace ReactNative.Bridge
{
    // TODO: Used by ReactShadowNode, which can't be pulled into Core right now
    public interface IGenericDelegate
    {
        object Invoke(object[] args);
    }
}
