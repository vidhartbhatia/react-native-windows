﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT
// v1.0.190111.3

#pragma once

#include "winrt/Windows.UI.Xaml.Automation.Provider.h"
#include "winrt/Windows.UI.Xaml.Automation.h"
#include "winrt/Windows.UI.Xaml.Controls.h"
#include "winrt/Windows.UI.Xaml.Media.h"
#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.h"
#include "winrt/react.uwp.h"


namespace winrt::react::uwp::implementation {

template <typename D, typename... I>
struct WINRT_EBO DynamicAutomationProperties_base
    : implements<D, react::uwp::IDynamicAutomationProperties, I...> {
  using base_type = DynamicAutomationProperties_base;
  using class_type = react::uwp::DynamicAutomationProperties;
  using implements_type =
      typename DynamicAutomationProperties_base::implements_type;
  using implements_type::implements_type;

#if _MSC_VER < 1914
  operator class_type() const noexcept {
    static_assert(std::is_same_v<
                  typename impl::implements_default_interface<D>::type,
                  default_interface<class_type>>);
    class_type result{nullptr};
    attach_abi(
        result, detach_abi(static_cast<default_interface<class_type>>(*this)));
    return result;
  }
#else
  operator impl::producer_ref<class_type> const() const noexcept {
    return {to_abi<default_interface<class_type>>(this)};
  }
#endif

  hstring GetRuntimeClassName() const {
    return L"react.uwp.DynamicAutomationProperties";
  }
};

} // namespace winrt::react::uwp::implementation

namespace winrt::react::uwp::factory_implementation {

template <typename D, typename T, typename... I>
struct WINRT_EBO DynamicAutomationPropertiesT
    : implements<
          D,
          Windows::Foundation::IActivationFactory,
          react::uwp::IDynamicAutomationPropertiesStatics,
          I...> {
  using instance_type = react::uwp::DynamicAutomationProperties;

  hstring GetRuntimeClassName() const {
    return L"react.uwp.DynamicAutomationProperties";
  }

  Windows::Foundation::IInspectable ActivateInstance() const {
    throw hresult_not_implemented();
  }

  Windows::UI::Xaml::DependencyProperty AccessibilityRoleProperty() {
    return T::AccessibilityRoleProperty();
  }

  void SetAccessibilityRole(
      Windows::UI::Xaml::UIElement const &element,
      react::uwp::AccessibilityRoles const &value) {
    T::SetAccessibilityRole(element, value);
  }

  react::uwp::AccessibilityRoles GetAccessibilityRole(
      Windows::UI::Xaml::UIElement const &element) {
    return T::GetAccessibilityRole(element);
  }

  Windows::UI::Xaml::DependencyProperty AccessibilityStateSelectedProperty() {
    return T::AccessibilityStateSelectedProperty();
  }

  void SetAccessibilityStateSelected(
      Windows::UI::Xaml::UIElement const &element,
      bool value) {
    T::SetAccessibilityStateSelected(element, value);
  }

  bool GetAccessibilityStateSelected(
      Windows::UI::Xaml::UIElement const &element) {
    return T::GetAccessibilityStateSelected(element);
  }

  Windows::UI::Xaml::DependencyProperty AccessibilityStateDisabledProperty() {
    return T::AccessibilityStateDisabledProperty();
  }

  void SetAccessibilityStateDisabled(
      Windows::UI::Xaml::UIElement const &element,
      bool value) {
    T::SetAccessibilityStateDisabled(element, value);
  }

  bool GetAccessibilityStateDisabled(
      Windows::UI::Xaml::UIElement const &element) {
    return T::GetAccessibilityStateDisabled(element);
  }

  Windows::UI::Xaml::DependencyProperty AccessibilityStateCheckedProperty() {
    return T::AccessibilityStateCheckedProperty();
  }

  void SetAccessibilityStateChecked(
      Windows::UI::Xaml::UIElement const &element,
      bool value) {
    T::SetAccessibilityStateChecked(element, value);
  }

  bool GetAccessibilityStateChecked(
      Windows::UI::Xaml::UIElement const &element) {
    return T::GetAccessibilityStateChecked(element);
  }

  Windows::UI::Xaml::DependencyProperty AccessibilityStateUncheckedProperty() {
    return T::AccessibilityStateUncheckedProperty();
  }

  void SetAccessibilityStateUnchecked(
      Windows::UI::Xaml::UIElement const &element,
      bool value) {
    T::SetAccessibilityStateUnchecked(element, value);
  }

  bool GetAccessibilityStateUnchecked(
      Windows::UI::Xaml::UIElement const &element) {
    return T::GetAccessibilityStateUnchecked(element);
  }

  Windows::UI::Xaml::DependencyProperty AccessibilityStateBusyProperty() {
    return T::AccessibilityStateBusyProperty();
  }

  void SetAccessibilityStateBusy(
      Windows::UI::Xaml::UIElement const &element,
      bool value) {
    T::SetAccessibilityStateBusy(element, value);
  }

  bool GetAccessibilityStateBusy(Windows::UI::Xaml::UIElement const &element) {
    return T::GetAccessibilityStateBusy(element);
  }

  Windows::UI::Xaml::DependencyProperty AccessibilityStateExpandedProperty() {
    return T::AccessibilityStateExpandedProperty();
  }

  void SetAccessibilityStateExpanded(
      Windows::UI::Xaml::UIElement const &element,
      bool value) {
    T::SetAccessibilityStateExpanded(element, value);
  }

  bool GetAccessibilityStateExpanded(
      Windows::UI::Xaml::UIElement const &element) {
    return T::GetAccessibilityStateExpanded(element);
  }

  Windows::UI::Xaml::DependencyProperty AccessibilityStateCollapsedProperty() {
    return T::AccessibilityStateCollapsedProperty();
  }

  void SetAccessibilityStateCollapsed(
      Windows::UI::Xaml::UIElement const &element,
      bool value) {
    T::SetAccessibilityStateCollapsed(element, value);
  }

  bool GetAccessibilityStateCollapsed(
      Windows::UI::Xaml::UIElement const &element) {
    return T::GetAccessibilityStateCollapsed(element);
  }

  Windows::UI::Xaml::DependencyProperty
  AccessibilityInvokeEventHandlerProperty() {
    return T::AccessibilityInvokeEventHandlerProperty();
  }

  void SetAccessibilityInvokeEventHandler(
      Windows::UI::Xaml::UIElement const &element,
      react::uwp::AccessibilityInvokeEventHandler const &value) {
    T::SetAccessibilityInvokeEventHandler(element, value);
  }

  react::uwp::AccessibilityInvokeEventHandler
  GetAccessibilityInvokeEventHandler(
      Windows::UI::Xaml::UIElement const &element) {
    return T::GetAccessibilityInvokeEventHandler(element);
  }
};

} // namespace winrt::react::uwp::factory_implementation

#if defined(WINRT_FORCE_INCLUDE_DYNAMICAUTOMATIONPROPERTIES_XAML_G_H) || \
    __has_include("DynamicAutomationProperties.xaml.g.h")

#include "DynamicAutomationProperties.xaml.g.h"

#else

namespace winrt::react::uwp::implementation {
template <typename D, typename... I>
using DynamicAutomationPropertiesT = DynamicAutomationProperties_base<D, I...>;
}

#endif
