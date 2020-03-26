// Copyright 2014-2017 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef TYPE_SUPPORT_COMMON_HPP_
#define TYPE_SUPPORT_COMMON_HPP_

#include <string>

#include "rmw/allocators.h"
#include "rmw/error_handling.h"

#include "rmw/impl/cpp/macros.hpp"

#include "rosidl_typesupport_opendds_c/identifier.h"
#include "rosidl_typesupport_opendds_cpp/identifier.hpp"
#include "rosidl_typesupport_opendds_cpp/message_type_support.h"
#include "rosidl_typesupport_opendds_cpp/service_type_support.h"

#define RMW_OPENDDS_EXTRACT_MESSAGE_TYPESUPPORT(TYPE_SUPPORTS, TYPE_SUPPORT, RET_VAL) \
  if (!TYPE_SUPPORTS) { \
    RMW_SET_ERROR_MSG("type supports handle is null"); \
    return RET_VAL; \
  } \
  const rosidl_message_type_support_t * TYPE_SUPPORT = \
    get_message_typesupport_handle( \
    TYPE_SUPPORTS, rosidl_typesupport_opendds_c__identifier); \
  if (!TYPE_SUPPORT) { \
    TYPE_SUPPORT = get_message_typesupport_handle( \
      TYPE_SUPPORTS, rosidl_typesupport_opendds_cpp::typesupport_identifier); \
    if (!TYPE_SUPPORT) { \
      char __msg[1024]; \
      snprintf( \
        __msg, 1024, \
        "type support handle implementation '%s' (%p) does not match valid type supports " \
        "('%s' (%p), '%s' (%p))", \
        TYPE_SUPPORTS->typesupport_identifier, \
        static_cast<const void *>(TYPE_SUPPORTS->typesupport_identifier), \
        rosidl_typesupport_opendds_cpp::typesupport_identifier, \
        static_cast<const void *>(rosidl_typesupport_opendds_cpp::typesupport_identifier), \
        rosidl_typesupport_opendds_c__identifier, \
        static_cast<const void *>(rosidl_typesupport_opendds_c__identifier)); \
      RMW_SET_ERROR_MSG(__msg); \
      return RET_VAL; \
    } \
  }

inline const rosidl_message_type_support_t *
rmw_get_message_type_support(const rosidl_message_type_support_t * type_support)
{
  if (!type_support) {
    RMW_SET_ERROR_MSG("type support is null");
    return nullptr;
  }
  const rosidl_message_type_support_t * ts =
    //get_message_typesupport_handle(type_support, rosidl_typesupport_opendds_cpp::typesupport_identifier);
    get_message_typesupport_handle(type_support, "rosidl_typesupport_c"); //for temporary testing
  if (!ts) {
    RMW_SET_ERROR_MSG_WITH_FORMAT_STRING("type support implementation '%s' does not match '%s'",
      type_support->typesupport_identifier, rosidl_typesupport_opendds_cpp::typesupport_identifier);
  }
  return ts;
}

#define RMW_OPENDDS_EXTRACT_SERVICE_TYPESUPPORT(TYPE_SUPPORTS, TYPE_SUPPORT, RET_VAL) \
  if (!TYPE_SUPPORTS) { \
    RMW_SET_ERROR_MSG("type supports handle is null"); \
    return RET_VAL; \
  } \
  const rosidl_service_type_support_t * TYPE_SUPPORT = \
    get_service_typesupport_handle( \
    TYPE_SUPPORTS, rosidl_typesupport_opendds_c__identifier); \
  if (!TYPE_SUPPORT) { \
    TYPE_SUPPORT = get_service_typesupport_handle( \
      TYPE_SUPPORTS, rosidl_typesupport_opendds_cpp::typesupport_identifier); \
    if (!TYPE_SUPPORT) { \
      char __msg[1024]; \
      snprintf( \
        __msg, 1024, \
        "type support handle implementation '%s' (%p) does not match valid type supports " \
        "('%s' (%p), '%s' (%p))", \
        TYPE_SUPPORTS->typesupport_identifier, \
        static_cast<const void *>(TYPE_SUPPORTS->typesupport_identifier), \
        rosidl_typesupport_opendds_cpp::typesupport_identifier, \
        static_cast<const void *>(rosidl_typesupport_opendds_cpp::typesupport_identifier), \
        rosidl_typesupport_opendds_c__identifier, \
        static_cast<const void *>(rosidl_typesupport_opendds_c__identifier)); \
      RMW_SET_ERROR_MSG(__msg); \
      return RET_VAL; \
    } \
  }


inline std::string
_create_type_name(
  const message_type_support_callbacks_t * callbacks,
  const std::string & sep)
{
  //return std::string(callbacks->message_namespace) + "::" + sep + "::dds_::" + callbacks->message_name + "_";
  return std::string("callbacks->message_namespace::" + sep + "::dds_::callbacks->message_name_"); //?? temp
}

#endif  // TYPE_SUPPORT_COMMON_HPP_
