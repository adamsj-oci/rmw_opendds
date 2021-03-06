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

#include <rmw_opendds_cpp/DDSSubscriber.hpp>
#include <rmw_opendds_cpp/DDSClient.hpp>
#include <rmw_opendds_cpp/DDSServer.hpp>
#include <rmw_opendds_cpp/wait.hpp>

#include <rmw/rmw.h>

extern "C"
{
rmw_ret_t
rmw_wait(
  rmw_subscriptions_t * subscriptions,
  rmw_guard_conditions_t * guard_conditions,
  rmw_services_t * services,
  rmw_clients_t * clients,
  rmw_events_t * events,
  rmw_wait_set_t * wait_set,
  const rmw_time_t * wait_timeout)
{
  return wait<DDSSubscriber, DDSServer, DDSClient>(
    subscriptions, guard_conditions, services, clients, events, wait_set, wait_timeout);
}
}  // extern "C"
