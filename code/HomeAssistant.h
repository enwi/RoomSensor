#pragma once

#include <map>

namespace HA
{
    namespace Entity
    {
        constexpr static const char* AlarmControlPanel PROGMEM = "alarm_control_panel";
        constexpr static const char* BinarySensor PROGMEM = "binary_sensor";
        constexpr static const char* Button PROGMEM = "button";
        constexpr static const char* Camera PROGMEM = "camera";
        constexpr static const char* Climate PROGMEM = "climate";
        constexpr static const char* Cover PROGMEM = "cover";
        constexpr static const char* DeviceTracker PROGMEM = "device_tracker";
        /// @brief AKA Device Trigger
        constexpr static const char* DeviceAutomation PROGMEM = "device_automation";
        constexpr static const char* Event PROGMEM = "event";
        constexpr static const char* Fan PROGMEM = "fan";
        constexpr static const char* Humidifier PROGMEM = "humidifier";
        constexpr static const char* Image PROGMEM = "image";
        constexpr static const char* Light PROGMEM = "light";
        constexpr static const char* Lock PROGMEM = "lock";
        constexpr static const char* Number PROGMEM = "number";
        constexpr static const char* Scene PROGMEM = "scene";
        constexpr static const char* Select PROGMEM = "select";
        constexpr static const char* Sensor PROGMEM = "sensor";
        constexpr static const char* Siren PROGMEM = "siren";
        constexpr static const char* Switch PROGMEM = "switch";
        constexpr static const char* Update PROGMEM = "update";
        constexpr static const char* Tag PROGMEM = "tag";
        constexpr static const char* Text PROGMEM = "text";
        constexpr static const char* Vacuum PROGMEM = "vacuum";
        constexpr static const char* WaterHeater PROGMEM = "water_heater";
    } // namespace Entity

    namespace Property
    {
        constexpr static const char* Device PROGMEM = "dev";
        constexpr static const char* DeviceClass PROGMEM = "dev_cla";
        constexpr static const char* DeviceConfigUrl PROGMEM = "cu";
        constexpr static const char* DeviceConnections PROGMEM = "cns";
        constexpr static const char* DeviceHardwareVersion PROGMEM = "hw";
        constexpr static const char* DeviceIdentifiers PROGMEM = "ids";
        constexpr static const char* DeviceManufacturer PROGMEM = "mf";
        constexpr static const char* DeviceModel PROGMEM = "mdl";
        constexpr static const char* DeviceSoftwareVersion PROGMEM = "sw";
        constexpr static const char* DeviceSuggestedArea = "sa";
        constexpr static const char* DeviceViaDevice = "via_device";

        /// @brief Can be DeviceName and Entity Name
        constexpr static const char* Name PROGMEM = "name";

        constexpr static const char* ActionTemplate PROGMEM = "act_tpl";
        constexpr static const char* AutomationType PROGMEM = "atype";
        constexpr static const char* AuxStateTemplate PROGMEM = "aux_stat_tpl";
        constexpr static const char* AvailableTones PROGMEM = "av_tones";
        constexpr static const char* Availability PROGMEM = "avty";
        constexpr static const char* AvailabilityMode PROGMEM = "avty_mode";
        constexpr static const char* AvailabilityTemplate PROGMEM = "avty_tpl";
        constexpr static const char* AwayModeStateTemplate PROGMEM = "away_mode_stat_tpl";
        constexpr static const char* BatteryLevelTemplate PROGMEM = "bat_lev_tpl";
        constexpr static const char* BlueTemplate PROGMEM = "b_tpl";
        constexpr static const char* BrightnessCommandTemplate PROGMEM = "bri_cmd_tpl";
        constexpr static const char* BrightnessScale PROGMEM = "bri_scl";
        constexpr static const char* BrightnessTemplate PROGMEM = "bri_tpl";
        constexpr static const char* BrightnessValueTemplate PROGMEM = "bri_val_tpl";
        constexpr static const char* ColorTempCommandTemplate PROGMEM = "clr_temp_cmd_tpl";
        constexpr static const char* ChargingTemplate PROGMEM = "chrg_tpl";
        constexpr static const char* ColorTempTemplate PROGMEM = "clr_temp_tpl";
        constexpr static const char* ColorTempValueTemplate PROGMEM = "clr_temp_val_tpl";
        constexpr static const char* ColorMode PROGMEM = "clrm";
        constexpr static const char* ColorModeValueTemplate PROGMEM = "clrm_val_tpl";
        constexpr static const char* CleaningTemplate PROGMEM = "cln_tpl";
        constexpr static const char* CommandOffTemplate PROGMEM = "cmd_off_tpl";
        constexpr static const char* CommandOnTemplate PROGMEM = "cmd_on_tpl";
        constexpr static const char* CommandTemplate PROGMEM = "cmd_tpl";
        constexpr static const char* CodeArmRequired PROGMEM = "cod_arm_req";
        constexpr static const char* CodeDisarmRequired PROGMEM = "cod_dis_req";
        constexpr static const char* CodeTriggerRequired PROGMEM = "cod_trig_req";
        constexpr static const char* ContentType PROGMEM = "cont_type";
        constexpr static const char* CurrentTemperatureTemplate PROGMEM = "curr_temp_tpl";
        constexpr static const char* DirectionCommandTemplate PROGMEM = "dir_cmd_tpl";
        constexpr static const char* DirectionValueTemplate PROGMEM = "dir_val_tpl";
        constexpr static const char* DockedTemplate PROGMEM = "dock_tpl";
        constexpr static const char* Encoding PROGMEM = "e";
        constexpr static const char* EnabledByDefault PROGMEM = "en";
        constexpr static const char* EntityCategory PROGMEM = "ent_cat";
        constexpr static const char* EntityPicture PROGMEM = "ent_pic";
        constexpr static const char* ErrorTemplate PROGMEM = "err_tpl";
        constexpr static const char* EventTypes PROGMEM = "evt_typ";
        constexpr static const char* FanSpeedTemplate PROGMEM = "fanspd_tpl";
        constexpr static const char* FanSpeedList PROGMEM = "fanspd_lst";
        constexpr static const char* FlashTimeLong PROGMEM = "flsh_tlng";
        constexpr static const char* FlashTimeShort PROGMEM = "flsh_tsht";
        constexpr static const char* EffectCommandTemplate PROGMEM = "fx_cmd_tpl";
        constexpr static const char* EffectList PROGMEM = "fx_list";
        constexpr static const char* EffectTemplate PROGMEM = "fx_tpl";
        constexpr static const char* EffectValueTemplate PROGMEM = "fx_val_tpl";
        constexpr static const char* ExpireAfter PROGMEM = "exp_aft";
        constexpr static const char* FanModeCommandTemplate PROGMEM = "fan_mode_cmd_tpl";
        constexpr static const char* FanModeStateTemplate PROGMEM = "fan_mode_stat_tpl";
        constexpr static const char* ForceUpdate PROGMEM = "frc_upd";
        constexpr static const char* GreenTemplate PROGMEM = "g_tpl";
        constexpr static const char* HsCommandTemplate PROGMEM = "hs_cmd_tpl";
        constexpr static const char* HsValueTemplate PROGMEM = "hs_val_tpl";
        constexpr static const char* Icon PROGMEM = "ic";
        constexpr static const char* ImageEncoding PROGMEM = "img_e";
        constexpr static const char* Initial PROGMEM = "init";
        constexpr static const char* TargetHumidityCommandTemplate PROGMEM = "hum_cmd_tpl";
        constexpr static const char* TargetHumidityStateTemplate PROGMEM = "hum_state_tpl";
        constexpr static const char* JsonAttributes PROGMEM = "json_attr";
        constexpr static const char* JsonAttributesTemplate PROGMEM = "json_attr_tpl";
        constexpr static const char* LatestVersionTemplate PROGMEM = "l_ver_tpl";
        constexpr static const char* LastResetValueTemplate PROGMEM = "lrst_val_tpl";
        constexpr static const char* Max PROGMEM = "max";
        constexpr static const char* Min PROGMEM = "min";
        constexpr static const char* MaxMireds PROGMEM = "max_mirs";
        constexpr static const char* MinMireds PROGMEM = "min_mirs";
        constexpr static const char* MaxTemp PROGMEM = "max_temp";
        constexpr static const char* MinTemp PROGMEM = "min_temp";
        constexpr static const char* MaxHumidity PROGMEM = "max_hum";
        constexpr static const char* MinHumidity PROGMEM = "min_hum";
        constexpr static const char* Mode PROGMEM = "mode";
        constexpr static const char* ModeCommandTemplate PROGMEM = "mode_cmd_tpl";
        constexpr static const char* ModeStateTemplate PROGMEM = "mode_stat_tpl";
        constexpr static const char* Modes PROGMEM = "modes";
        constexpr static const char* ObjectId PROGMEM = "obj_id";
        constexpr static const char* OffDelay PROGMEM = "off_dly";
        constexpr static const char* OnCommandType PROGMEM = "on_cmd_type";
        constexpr static const char* Options PROGMEM = "ops";
        constexpr static const char* Optimistic PROGMEM = "opt";
        constexpr static const char* OscillationCommandTemplate PROGMEM = "osc_cmd_tpl";
        constexpr static const char* OscillationValueTemplate PROGMEM = "osc_val_tpl";
        constexpr static const char* PercentageCommandTemplate PROGMEM = "pct_cmd_tpl";
        constexpr static const char* PercentageValueTemplate PROGMEM = "pct_val_tpl";
        constexpr static const char* Pattern PROGMEM = "ptrn";
        constexpr static const char* Payload PROGMEM = "pl";
        constexpr static const char* PayloadArmAway PROGMEM = "pl_arm_away";
        constexpr static const char* PayloadArmHome PROGMEM = "pl_arm_home";
        constexpr static const char* PayloadArmCustomBypass PROGMEM = "pl_arm_custom_b";
        constexpr static const char* PayloadArmNight PROGMEM = "pl_arm_nite";
        constexpr static const char* PayloadArmVacation PROGMEM = "pl_arm_vacation";
        constexpr static const char* PayloadPress PROGMEM = "pl_prs";
        constexpr static const char* PayloadReset PROGMEM = "pl_rst";
        constexpr static const char* PayloadAvailable PROGMEM = "pl_avail";
        constexpr static const char* PayloadCleanSpot PROGMEM = "pl_cln_sp";
        constexpr static const char* PayloadClose PROGMEM = "pl_cls";
        constexpr static const char* PayloadDisarm PROGMEM = "pl_disarm";
        constexpr static const char* PayloadDirectionForward PROGMEM = "pl_dir_fwd";
        constexpr static const char* PayloadDirectionReverse PROGMEM = "pl_dir_rev";
        constexpr static const char* PayloadHome PROGMEM = "pl_home";
        constexpr static const char* PayloadInstall PROGMEM = "pl_inst";
        constexpr static const char* PayloadLock PROGMEM = "pl_lock";
        constexpr static const char* PayloadLocate PROGMEM = "pl_loc";
        constexpr static const char* PayloadNotAvailable PROGMEM = "pl_not_avail";
        constexpr static const char* PayloadNotHome PROGMEM = "pl_not_home";
        constexpr static const char* PayloadOff PROGMEM = "pl_off";
        constexpr static const char* PayloadOn PROGMEM = "pl_on";
        constexpr static const char* PayloadOpen PROGMEM = "pl_open";
        constexpr static const char* PayloadOscillationOff PROGMEM = "pl_osc_off";
        constexpr static const char* PayloadOscillationOn PROGMEM = "pl_osc_on";
        constexpr static const char* PayloadPause PROGMEM = "pl_paus";
        constexpr static const char* PayloadStop PROGMEM = "pl_stop";
        constexpr static const char* PayloadStart PROGMEM = "pl_strt";
        constexpr static const char* PayloadStartPause PROGMEM = "pl_stpa";
        constexpr static const char* PayloadReturnToBase PROGMEM = "pl_ret";
        constexpr static const char* PayloadResetHumidity PROGMEM = "pl_rst_hum";
        constexpr static const char* PayloadResetMode PROGMEM = "pl_rst_mode";
        constexpr static const char* PayloadResetPercentage PROGMEM = "pl_rst_pct";
        constexpr static const char* PayloadResetPresetMode PROGMEM = "pl_rst_pr_mode";
        constexpr static const char* PayloadTurnOff PROGMEM = "pl_toff";
        constexpr static const char* PayloadTurnOn PROGMEM = "pl_ton";
        constexpr static const char* PayloadTrigger PROGMEM = "pl_trig";
        constexpr static const char* PayloadUnlock PROGMEM = "pl_unlk";
        constexpr static const char* PositionTemplate PROGMEM = "pos_tpl";
        constexpr static const char* PositionClosed PROGMEM = "pos_clsd";
        constexpr static const char* PositionOpen PROGMEM = "pos_open";
        constexpr static const char* PresetModeCommandTemplate PROGMEM = "pr_mode_cmd_tpl";
        constexpr static const char* PresetModeValueTemplate PROGMEM = "pr_mode_val_tpl";
        constexpr static const char* PresetModes PROGMEM = "pr_modes";
        constexpr static const char* RedTemplate PROGMEM = "r_tpl";
        constexpr static const char* ReleaseSummary PROGMEM = "rel_s";
        constexpr static const char* ReleaseUrl PROGMEM = "rel_u";
        constexpr static const char* Retain PROGMEM = "ret";
        constexpr static const char* RgbCommandTemplate PROGMEM = "rgb_cmd_tpl";
        constexpr static const char* RgbValueTemplate PROGMEM = "rgb_val_tpl";
        constexpr static const char* RgbwCommandTemplate PROGMEM = "rgbw_cmd_tpl";
        constexpr static const char* RgbwValueTemplate PROGMEM = "rgbw_val_tpl";
        constexpr static const char* RgbwwCommandTemplate PROGMEM = "rgbww_cmd_tpl";
        constexpr static const char* RgbwwValueTemplate PROGMEM = "rgbww_val_tpl";
        constexpr static const char* SendIfOff PROGMEM = "send_if_off";
        constexpr static const char* SetPositionTemplate PROGMEM = "set_pos_tpl";
        constexpr static const char* SpeedRangeMin PROGMEM = "spd_rng_min";
        constexpr static const char* SpeedRangeMax PROGMEM = "spd_rng_max";
        constexpr static const char* SourceType PROGMEM = "src_type";
        /// @brief One of measurement, total or total_increasing
        constexpr static const char* StateClass PROGMEM = "stat_cla";
        constexpr static const char* StateClosed PROGMEM = "stat_clsd";
        constexpr static const char* StateClosing PROGMEM = "stat_closing";
        constexpr static const char* StateJammed PROGMEM = "stat_jam";
        constexpr static const char* StateOff PROGMEM = "stat_off";
        constexpr static const char* StateOn PROGMEM = "stat_on";
        constexpr static const char* StateOpen PROGMEM = "stat_open";
        constexpr static const char* StateOpening PROGMEM = "stat_opening";
        constexpr static const char* StateStopped PROGMEM = "stat_stopped";
        constexpr static const char* StateLocked PROGMEM = "stat_locked";
        constexpr static const char* StateLocking PROGMEM = "stat_locking";
        constexpr static const char* StateUnlocked PROGMEM = "stat_unlocked";
        constexpr static const char* StateUnlocking PROGMEM = "stat_unlocking";
        constexpr static const char* StateTemplate PROGMEM = "stat_tpl";
        constexpr static const char* StateValueTemplate PROGMEM = "stat_val_tpl";
        constexpr static const char* Step PROGMEM = "step";
        constexpr static const char* Subtype PROGMEM = "stype";
        constexpr static const char* SuggestedDisplayPrecision PROGMEM = "sug_dsp_prc";
        constexpr static const char* SupportedColorModes PROGMEM = "sup_clrm";
        constexpr static const char* SupportDuration PROGMEM = "sup_dur";
        constexpr static const char* SupportVolumeSet PROGMEM = "sup_vol";
        constexpr static const char* SupportedFeatures PROGMEM = "sup_feat";
        constexpr static const char* SwingModeCommandTemplate PROGMEM = "swing_mode_cmd_tpl";
        constexpr static const char* SwingModeStateTemplate PROGMEM = "swing_mode_stat_tpl";
        constexpr static const char* TemperatureCommandTemplate PROGMEM = "temp_cmd_tpl";
        constexpr static const char* TemperatureHighCommandTemplate PROGMEM = "temp_hi_cmd_tpl";
        constexpr static const char* TemperatureHighStateTemplate PROGMEM = "temp_hi_stat_tpl";
        constexpr static const char* TemperatureLowCommandTemplate PROGMEM = "temp_lo_cmd_tpl";
        constexpr static const char* TemperatureLowStateTemplate PROGMEM = "temp_lo_stat_tpl";
        constexpr static const char* TemperatureStateTemplate PROGMEM = "temp_stat_tpl";
        constexpr static const char* TemperatureUnit PROGMEM = "temp_unit";
        constexpr static const char* TiltClosedValue PROGMEM = "tilt_clsd_val";
        constexpr static const char* TiltCommandTemplate PROGMEM = "tilt_cmd_tpl";
        constexpr static const char* TiltMax PROGMEM = "tilt_max";
        constexpr static const char* TiltMin PROGMEM = "tilt_min";
        constexpr static const char* TiltOpenedValue PROGMEM = "tilt_opnd_val";
        constexpr static const char* TiltOptimistic PROGMEM = "tilt_opt";
        constexpr static const char* TiltStatusTemplate PROGMEM = "tilt_status_tpl";
        constexpr static const char* Title PROGMEM = "tit";
        constexpr static const char* UniqueId PROGMEM = "uniq_id";
        constexpr static const char* UnitOfMeasurement PROGMEM = "unit_of_meas";
        constexpr static const char* UrlTemplate PROGMEM = "url_tpl";
        constexpr static const char* ValueTemplate PROGMEM = "val_tpl";
        constexpr static const char* whiteScale PROGMEM = "whit_scl";
        constexpr static const char* XyCommandTemplate PROGMEM = "xy_cmd_tpl";
        constexpr static const char* XyValueTemplate PROGMEM = "xy_val_tpl";
    } // namespace Property

    namespace Topic
    {
        constexpr static const char* Action PROGMEM = "act_t";
        constexpr static const char* AuxCommand PROGMEM = "aux_cmd_t";
        constexpr static const char* AuxState PROGMEM = "aux_stat_t";
        constexpr static const char* Availability PROGMEM = "avty_t";
        constexpr static const char* AwayModeCommand PROGMEM = "away_mode_cmd_t";
        constexpr static const char* AwayModeState PROGMEM = "away_mode_stat_t";
        constexpr static const char* Base PROGMEM = "~";
        constexpr static const char* BatteryLevel PROGMEM = "bat_lev_t";
        constexpr static const char* BrightnessCommand PROGMEM = "bri_cmd_t";
        constexpr static const char* BrightnessState PROGMEM = "bri_stat_t";
        constexpr static const char* Charging PROGMEM = "chrg_t";
        constexpr static const char* ColorTempCommand PROGMEM = "clr_temp_cmd_t";
        constexpr static const char* ColorTempState PROGMEM = "clr_temp_stat_t";
        constexpr static const char* ColorModeState PROGMEM = "clrm_stat_t";
        constexpr static const char* Cleaning PROGMEM = "cln_t";
        constexpr static const char* Command PROGMEM = "cmd_t";
        constexpr static const char* CurrentTemperature PROGMEM = "curr_temp_t";
        constexpr static const char* DirectionCommand PROGMEM = "dir_cmd_t";
        constexpr static const char* DirectionState PROGMEM = "dir_stat_t";
        constexpr static const char* Docked PROGMEM = "dock_t";
        constexpr static const char* Error PROGMEM = "err_t";
        constexpr static const char* EffectCommand PROGMEM = "fx_cmd_t";
        constexpr static const char* EffectState PROGMEM = "fx_stat_t";
        constexpr static const char* FanSpeed PROGMEM = "fanspd_t";
        constexpr static const char* FanModeCommand PROGMEM = "fan_mode_cmd_t";
        constexpr static const char* FanModeState PROGMEM = "fan_mode_stat_t";
        constexpr static const char* HsCommand PROGMEM = "hs_cmd_t";
        constexpr static const char* HsState PROGMEM = "hs_stat_t";
        constexpr static const char* Image PROGMEM = "img_t";
        constexpr static const char* JsonAttributes PROGMEM = "json_attr_t";
        constexpr static const char* LatestVersion PROGMEM = "l_ver_t";
        constexpr static const char* LastReset PROGMEM = "lrst_t";
        constexpr static const char* ModeCommand PROGMEM = "mode_cmd_t";
        constexpr static const char* ModeState PROGMEM = "mode_stat_t";
        constexpr static const char* OscillationCommand PROGMEM = "osc_cmd_t";
        constexpr static const char* OscillationState PROGMEM = "osc_stat_t";
        constexpr static const char* Position PROGMEM = "pos_t";
        constexpr static const char* PercentageCommand PROGMEM = "pct_cmd_t";
        constexpr static const char* PercentageState PROGMEM = "pct_stat_t";
        constexpr static const char* PresetModeCommand PROGMEM = "pr_mode_cmd_t";
        constexpr static const char* PresetModeState PROGMEM = "pr_mode_stat_t";
        constexpr static const char* RgbCommand PROGMEM = "rgb_cmd_t";
        constexpr static const char* RgbState PROGMEM = "rgb_stat_t";
        constexpr static const char* RgbwCommand PROGMEM = "rgbw_cmd_t";
        constexpr static const char* RgbwState PROGMEM = "rgbw_stat_t";
        constexpr static const char* RgbwwCommand PROGMEM = "rgbww_cmd_t";
        constexpr static const char* RgbwwState PROGMEM = "rgbww_stat_t";
        constexpr static const char* SendCommand PROGMEM = "send_cmd_t";
        constexpr static const char* SetFanSpeed PROGMEM = "set_fan_spd_t";
        constexpr static const char* SetPosition PROGMEM = "set_pos_t";
        constexpr static const char* State PROGMEM = "stat_t";
        constexpr static const char* SwingModeCommand PROGMEM = "swing_mode_cmd_t";
        constexpr static const char* SwingModeState PROGMEM = "swing_mode_stat_t";
        constexpr static const char* TargetHumidityCommand PROGMEM = "hum_cmd_t";
        constexpr static const char* TargetHumidityState PROGMEM = "hum_stat_t";
        constexpr static const char* TemperatureCommand PROGMEM = "temp_cmd_t";
        constexpr static const char* TemperatureHighCommand PROGMEM = "temp_hi_cmd_t";
        constexpr static const char* TemperatureHighState PROGMEM = "temp_hi_stat_t";
        constexpr static const char* TemperatureLowCommand PROGMEM = "temp_lo_cmd_t";
        constexpr static const char* TemperatureLowState PROGMEM = "temp_lo_stat_t";
        constexpr static const char* TemperatureState PROGMEM = "temp_stat_t";
        constexpr static const char* TiltCommand PROGMEM = "tilt_cmd_t";
        constexpr static const char* TiltStatus PROGMEM = "tilt_status_t";
        constexpr static const char* Topic PROGMEM = "t";
        constexpr static const char* Url PROGMEM = "url_t";
        constexpr static const char* whiteCommand PROGMEM = "whit_cmd_t";
        constexpr static const char* XyCommand PROGMEM = "xy_cmd_t";
        constexpr static const char* XyState PROGMEM = "xy_stat_t";
    } // namespace Topic

    // struct AProperty
    // {
    //     const char* key;
    //     const char* value;

    //     constexpr AProperty(const char* key, const char* value) : key(key), value(value) { }
    // };

    // template <size_t N>
    // class TestEntity
    // {
    // public:
    //     constexpr TestEntity(const std::array<AProperty, N>& properties) : properties(properties) { }

    //     bool publishDiscovery(std::function<bool(const String&, const JsonDocument&, const bool retain)> publish)
    //     {
    //         StaticJsonDocument<600> autoConfig;
    //         for (const auto& entry : properties)
    //         {
    //             autoConfig[entry.key] = entry.value;
    //         }

    //         return publish("", autoConfig, true);
    //     }

    //     std::array<AProperty, N> properties;
    // };

    // constexpr static const auto bli = TestEntity<1>({AProperty(Property::UniqueId, "")});

    // template <typename... properties>
    // TestEntity<sizeof...(properties)> make_entity(properties p)
    // {
    //     return TestEntity<sizeof...(p)>(p);
    // }

    // constexpr static const auto hallal = make_entity(AProperty(Property::UniqueId, ""));

    // class Device
    // {
    // public:
    //     constexpr Device(const char* uid) : m_uid(uid) { }

    //     constexpr const char* getUid() { return m_uid; }

    //     void setManufacturer(const char* manufacturer) { m_manufacturer = manufacturer; }

    // private:
    //     constexpr const char* m_uid;
    //     constexpr const char* m_manufacturer = nullptr;
    // };

    typedef struct Device
    {
        const char* uid;
        const char* configurationUrl;
        // todo connections
        const char* hardwareVersion;
        // todo identifiers
        const char* manufacturer;
        const char* model;
        const char* name;
        const char* suggestedArea;
        const char* softwareVersion;
        const char* viaDevice;

        void publish()
        {
            if (!uid)
            {
                return;
            }
        }
    };

    constexpr static const Device myDevice = {
        .uid = "",
        .manufacturer = "test",
    };

    class BEntity
    {
    public:
        BEntity(const char* type, const char* uid) : type(type), uid(uid) { }
        const char* type;
        const char* uid;
    };

    class BSensor : public BEntity
    {
    public:
        BSensor(const char* type, const char* uid, const char* unitOfMeasurement)
            : BEntity(type, uid), unitOfMeasurement(unitOfMeasurement)
        { }

        const char* unitOfMeasurement;
    };

    // class BSensorBuilder
    // {
    //     const char* type;
    //     const char* uid;
    //     const char* unitOfMeasurement;

    // public:
    //     constexpr BSensorBuilder setType(const char* type)
    //     {
    //         this->type = type;
    //         return *this;
    //     }
    //     constexpr BSensorBuilder setUid(const char* uid)
    //     {
    //         this->uid = uid;
    //         return *this;
    //     }
    //     constexpr BSensorBuilder setUnitOfMeasurement(const char* unitOfMeasurement)
    //     {
    //         this->unitOfMeasurement = unitOfMeasurement;
    //         return *this;
    //     }

    //     constexpr BSensor get() { return BSensor(type, uid, unitOfMeasurement); }
    // };

    // constexpr static const auto blurp = BSensorBuilder().setUid("hallal").get();

    // constexpr static const BSensor mySensor = {
    //     {
    //         .uid = "",
    //     },
    //     .unitOfMeasurement = "test",
    // };

    // class DeviceBuilder
    // {
    // public:
    //     constexpr DeviceBuilder(/* args */) { }
    // };

    class BaseEntity
    {
    public:
        BaseEntity(const char* type, const char* uid) : m_type(type) { setProperty(Property::UniqueId, uid); }

        constexpr const char* getType() { return m_type; }
        constexpr const char* getUid() { return m_properties.at(Property::UniqueId); }

        bool publishDiscovery(std::function<bool(const String&, const JsonDocument&, const bool retain)> publish)
        {
            StaticJsonDocument<600> autoConfig;
            for (const auto& entry : m_properties)
            {
                autoConfig[entry.first] = entry.second;
            }

            return publish("", autoConfig, true);
        }

        bool publishJSON(PubSubClient& mqtt, const String& topic, const JsonDocument& json, const bool retain = false)
        {
            const size_t size = measureJson(json);
            if (!mqtt.beginPublish(topic.c_str(), size, true))
            {
                RS_DEBUGF("[MQTT] Could not begin publish with size %d\n", size);
                return false;
            }
            serializeJson(json, mqtt);
            return mqtt.endPublish();

            // char jsonStr[600];
            // serializeJson(json, jsonStr);
            // mqtt.publish(topic.c_str(), 0, true, jsonStr);
            // return true;
        }

    protected:
        void setProperty(const char* property, const char* value) { m_properties[property] = value; }
        virtual void add() = 0;

    private:
        void addDeviceInfo(JsonDocument& json, const String& deviceID)
        {
            auto dev = json[HA::Property::Device];
            dev[HA::Property::DeviceManufacturer] = "enwi";
            // dev[HA::Property::DeviceModel] = String(MODEL) + " " + HARDWARE_VERSION;
            dev[HA::Property::Name] = deviceID;
            // dev[HA::Property::DeviceSoftwareVersion] = SOFTWARE_VERSION;
            dev[HA::Property::DeviceConfigUrl] = String("http://") + WiFi.localIP().toString();

            dev.createNestedArray(HA::Property::DeviceIdentifiers).add(deviceID);
        }

    private:
        const char* m_type;
        std::map<const char*, const char*> m_properties = {};
    };

    class Sensor : public BaseEntity
    {
    public:
        Sensor(const char* uid) : BaseEntity(HA::Entity::Sensor, uid) { }

        void add() override { }

        void setUnitOfMeasurement(const char* unit) { setProperty(Property::UnitOfMeasurement, unit); }
    };

    template <SensorClass clazz, Unit unit>
    Sensor make_sensor(const char* uid)
    {
        Sensor sensor = Sensor(uid);
        sensor.setUnitOfMeasurement(toStr<unit>());
        return sensor;
    }

} // namespace HA
