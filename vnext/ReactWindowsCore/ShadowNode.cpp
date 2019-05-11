// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "ShadowNode.h"

namespace facebook { namespace react {

LegacyShadowNode::~LegacyShadowNode() {}

void LegacyShadowNode::dispatchCommand(int64_t commandId, const folly::dynamic& commandArgs) {}

void LegacyShadowNode::onDropViewInstance() {}

void LegacyShadowNode::updateProperties(const folly::dynamic&& props) {}

}} // namespace facebook::react
