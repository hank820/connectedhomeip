/**
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include <app/util/af.h>

#include <app/util/af-event.h>
#include <app/util/attribute-storage.h>

#include "gen/attribute-id.h"
#include "gen/attribute-type.h"
#include "gen/cluster-id.h"

using namespace chip;

void emberAfThermostatClusterServerInitCallback(void)
{
    // TODO
}

bool emberAfThermostatClusterClearWeeklyScheduleCallback()
{
    // TODO
    return false;
}
bool emberAfThermostatClusterGetRelayStatusLogCallback()
{
    // TODO
    return false;
}

bool emberAfThermostatClusterGetWeeklyScheduleCallback(uint8_t daysToReturn, uint8_t modeToReturn)
{
    // TODO
    return false;
}

bool emberAfThermostatClusterSetWeeklyScheduleCallback(uint8_t numberOfTransitionsForSequence, uint8_t daysOfWeekForSequence,
                                                       uint8_t modeForSequence, uint8_t * payload)
{
    // TODO
    return false;
}

bool emberAfThermostatClusterSetpointRaiseLowerCallback(uint8_t mode, int8_t amount)
{
    // TODO
    return false;
}
