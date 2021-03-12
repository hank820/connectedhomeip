/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2018 Nest Labs, Inc.
 *    All rights reserved.
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

/**
 *    @file
 *          Provides the implementation of the Device Layer ConfigurationManager object
 *          for the ESP32.
 */
/* this file behaves like a config.h, comes first */
#include <platform/internal/CHIPDeviceLayerInternal.h>

#include <platform/ConfigurationManager.h>
#include <platform/AMBD/AMBDConfig.h>
#include <platform/internal/GenericConfigurationManagerImpl.cpp>
#include <support/CodeUtils.h>
#include <support/logging/CHIPLogging.h>

namespace chip {
namespace DeviceLayer {

using namespace ::chip::DeviceLayer::Internal;

/** Singleton instance of the ConfigurationManager implementation object.
 */
ConfigurationManagerImpl ConfigurationManagerImpl::sInstance;

CHIP_ERROR ConfigurationManagerImpl::_Init()
{
    CHIP_ERROR err;
    bool failSafeArmed;

    // Initialize the generic implementation base class.
    err = Internal::GenericConfigurationManagerImpl<ConfigurationManagerImpl>::_Init();
    SuccessOrExit(err);

    // TODO: initialize NVM component

    // If the fail-safe was armed when the device last shutdown, initiate a factory reset.
    if (_GetFailSafeArmed(failSafeArmed) == CHIP_NO_ERROR && failSafeArmed)
    {
        ChipLogProgress(DeviceLayer, "Detected fail-safe armed on reboot; initiating factory reset");
        _InitiateFactoryReset();
    }
    err = CHIP_NO_ERROR;

exit:
    return err;
}

CHIP_ERROR ConfigurationManagerImpl::_GetPrimaryWiFiMACAddress(uint8_t * buf)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

bool ConfigurationManagerImpl::_CanFactoryReset()
{
    // TODO: query the application to determine if factory reset is allowed.
    return true;
}

void ConfigurationManagerImpl::_InitiateFactoryReset()
{
    PlatformMgr().ScheduleWork(DoFactoryReset);
}

CHIP_ERROR ConfigurationManagerImpl::_ReadPersistedStorageValue(::chip::Platform::PersistedStorage::Key persistedStorageKey,
                                                                uint32_t & value)
{
#if 0
    CHIP_ERROR err;
    uintmax_t recordKey = persistedStorageKey + kConfigKey_GroupKeyBase;

    VerifyOrExit(recordKey <= kConfigKey_GroupKeyMax, err = CHIP_ERROR_PERSISTED_STORAGE_VALUE_NOT_FOUND);

    err = ReadConfigValue(persistedStorageKey, value);
    if (err == CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND)
    {
        err = CHIP_ERROR_PERSISTED_STORAGE_VALUE_NOT_FOUND;
    }
    SuccessOrExit(err);

exit:
    return err;
#else
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
#endif
}

CHIP_ERROR ConfigurationManagerImpl::_WritePersistedStorageValue(::chip::Platform::PersistedStorage::Key persistedStorageKey,
                                                                 uint32_t value)
{
#if 0
    CHIP_ERROR err;

    uintmax_t recordKey = persistedStorageKey + kConfigKey_GroupKeyBase;

    VerifyOrExit(recordKey <= kConfigKey_GroupKeyMax, err = CHIP_ERROR_PERSISTED_STORAGE_VALUE_NOT_FOUND);

    err = WriteConfigValue(persistedStorageKey, value);
    SuccessOrExit(err);

exit:
    return err;
#else
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
#endif
}

void ConfigurationManagerImpl::DoFactoryReset(intptr_t arg)
{
#if 0
    CHIP_ERROR err;

    ChipLogProgress(DeviceLayer, "Performing factory reset");

    err = FactoryResetConfig();
    if (err != CHIP_NO_ERROR)
    {
        ChipLogError(DeviceLayer, "FactoryResetConfig() failed: %s", ErrorStr(err));
    }

#if CHIP_DEVICE_CONFIG_ENABLE_THREAD

    ChipLogProgress(DeviceLayer, "Clearing Thread provision");
    ThreadStackMgr().ErasePersistentInfo();

#endif // CHIP_DEVICE_CONFIG_ENABLE_THREAD

    // Restart the system.
    ChipLogProgress(DeviceLayer, "System restarting");
    // NVIC_SystemReset(); - FIXME
#else
	ChipLogProgress(DeviceLayer, "System restarting");
    //return CHIP_NO_ERROR;
#endif
}

} // namespace DeviceLayer
} // namespace chip