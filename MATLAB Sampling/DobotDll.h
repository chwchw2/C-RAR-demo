#ifndef DOBOTDLL_H
#define DOBOTDLL_H

#include "DobotType.h"

__declspec(dllimport) int DobotExec(void);

__declspec(dllimport) int SearchDobot(char *dobotNameList, uint32_t maxLen);
__declspec(dllimport) int ConnectDobot(const char *portName, uint32_t baudrate, char *fwType, char *version, float *time);
__declspec(dllimport) int DisconnectDobot(void);
__declspec(dllimport) int GetMarlinVersion(void);

__declspec(dllimport) int SetCmdTimeout(uint32_t cmdTimeout);

// Device information
__declspec(dllimport) int SetDeviceSN(const char *deviceSN);
__declspec(dllimport) int GetDeviceSN(char *deviceSN, uint32_t maxLen);

__declspec(dllimport) int SetDeviceName(const char *deviceName);
__declspec(dllimport) int GetDeviceName(char *deviceName, uint32_t maxLen);

__declspec(dllimport) int GetDeviceVersion(uint8_t *majorVersion, uint8_t *minorVersion, uint8_t *revision, uint8_t *hwVersion);

__declspec(dllimport) int SetDeviceWithL(bool isWithL, uint8_t version, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetDeviceWithL(bool *isWithL);

__declspec(dllimport) int GetDeviceTime(uint32_t *deviceTime);
__declspec(dllimport) int GetDeviceInfo(DeviceCountInfo *deviceInfo);

// Pose and Kinematics parameters are automatically get
__declspec(dllimport) int GetPose(Pose *pose);
__declspec(dllimport) int ResetPose(bool manual, float rearArmAngle, float frontArmAngle);
__declspec(dllimport) int GetKinematics(Kinematics *kinematics);
__declspec(dllimport) int GetPoseL(float *l);

// Alarms
__declspec(dllimport) int GetAlarmsState(uint8_t *alarmsState, uint32_t *len, uint32_t maxLen);
__declspec(dllimport) int ClearAllAlarmsState(void);

// HOME
__declspec(dllimport) int SetHOMEParams(HOMEParams *homeParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetHOMEParams(HOMEParams *homeParams);

__declspec(dllimport) int SetHOMECmd(HOMECmd *homeCmd, bool isQueued, uint64_t *queuedCmdIndex);

__declspec(dllimport) int SetAutoLevelingCmd(AutoLevelingCmd *autoLevelingCmd, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetAutoLevelingResult(float *precision);

// Handheld teach
__declspec(dllimport) int SetHHTTrigMode(HHTTrigMode hhtTrigMode);
__declspec(dllimport) int GetHHTTrigMode(HHTTrigMode *hhtTrigMode);

__declspec(dllimport) int SetHHTTrigOutputEnabled(bool isEnabled);
__declspec(dllimport) int GetHHTTrigOutputEnabled(bool *isEnabled);

__declspec(dllimport) int GetHHTTrigOutput(bool *isTriggered);

// EndEffector
__declspec(dllimport) int SetEndEffectorParams(EndEffectorParams *endEffectorParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetEndEffectorParams(EndEffectorParams *endEffectorParams);

__declspec(dllimport) int SetEndEffectorLaser(bool enableCtrl, bool on, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetEndEffectorLaser(bool *isCtrlEnabled, bool *isOn);

__declspec(dllimport) int SetEndEffectorSuctionCup(bool enableCtrl, bool suck, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetEndEffectorSuctionCup(bool *isCtrlEnabled, bool *isSucked);

__declspec(dllimport) int SetEndEffectorGripper(bool enableCtrl, bool grip, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetEndEffectorGripper(bool *isCtrlEnabled, bool *isGripped);

// Arm orientation
__declspec(dllimport) int SetArmOrientation(ArmOrientation armOrientation, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetArmOrientation(ArmOrientation *armOrientation);

// JOG functions
__declspec(dllimport) int SetJOGJointParams(JOGJointParams *jointJogParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetJOGJointParams(JOGJointParams *jointJogParams);

__declspec(dllimport) int SetJOGCoordinateParams(JOGCoordinateParams *coordinateJogParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetJOGCoordinateParams(JOGCoordinateParams *coordinateJogParams);

__declspec(dllimport) int SetJOGLParams(JOGLParams *jogLParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetJOGLParams(JOGLParams *jogLParams);

__declspec(dllimport) int SetJOGCommonParams(JOGCommonParams *jogCommonParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetJOGCommonParams(JOGCommonParams *jogCommonParams);
__declspec(dllimport) int SetJOGCmd(JOGCmd *jogCmd, bool isQueued, uint64_t *queuedCmdIndex);

// PTP functions
__declspec(dllimport) int SetPTPJointParams(PTPJointParams *ptpJointParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetPTPJointParams(PTPJointParams *ptpJointParams);
__declspec(dllimport) int SetPTPCoordinateParams(PTPCoordinateParams *ptpCoordinateParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetPTPCoordinateParams(PTPCoordinateParams *ptpCoordinateParams);
__declspec(dllimport) int SetPTPLParams(PTPLParams *ptpLParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetPTPLParams(PTPLParams *ptpLParams);

__declspec(dllimport) int SetPTPJumpParams(PTPJumpParams *ptpJumpParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetPTPJumpParams(PTPJumpParams *ptpJumpParams);
__declspec(dllimport) int SetPTPCommonParams(PTPCommonParams *ptpCommonParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetPTPCommonParams(PTPCommonParams *ptpCommonParams);

__declspec(dllimport) int SetPTPCmd(PTPCmd *ptpCmd, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int SetPTPWithLCmd(PTPWithLCmd *ptpWithLCmd, bool isQueued, uint64_t *queuedCmdIndex);

__declspec(dllimport) int SetPTPJump2Params(PTPJump2Params *ptpJump2Params, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetPTPJump2Params(PTPJump2Params *ptpJump2Params);

__declspec(dllimport) int SetPTPPOCmd(PTPCmd *ptpCmd, ParallelOutputCmd *parallelCmd, int parallelCmdCount, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int SetPTPPOWithLCmd(PTPWithLCmd *ptpWithLCmd, ParallelOutputCmd *parallelCmd, int parallelCmdCount, bool isQueued, uint64_t *queuedCmdIndex);

// CP functions
__declspec(dllimport) int SetCPParams(CPParams *cpParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetCPParams(CPParams *cpParams);
__declspec(dllimport) int SetCPCmd(CPCmd *cpCmd, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int SetCPLECmd(CPCmd *cpCmd, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int SetCPRHoldEnable(bool isEnable);
__declspec(dllimport) int GetCPRHoldEnable(bool *isEnable);
__declspec(dllimport) int SetCPCommonParams(CPCommonParams *cpCommonParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetCPCommonParams(CPCommonParams *cpCommonParams);

// ARC
__declspec(dllimport) int SetARCParams(ARCParams *arcParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetARCParams(ARCParams *arcParams);
__declspec(dllimport) int SetARCCmd(ARCCmd *arcCmd, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int SetCircleCmd(CircleCmd *circleCmd, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int SetARCCommonParams(ARCCommonParams *arcCommonParams, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetARCCommonParams(ARCCommonParams *arcCommonParams);

// WAIT
__declspec(dllimport) int SetWAITCmd(WAITCmd *waitCmd, bool isQueued, uint64_t *queuedCmdIndex);

// TRIG
__declspec(dllimport) int SetTRIGCmd(TRIGCmd *trigCmd, bool isQueued, uint64_t *queuedCmdIndex);

// EIO
__declspec(dllimport) int SetIOMultiplexing(IOMultiplexing *ioMultiplexing, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetIOMultiplexing(IOMultiplexing *ioMultiplexing);

__declspec(dllimport) int SetIODO(IODO *ioDO, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetIODO(IODO *ioDO);

__declspec(dllimport) int SetIOPWM(IOPWM *ioPWM, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int GetIOPWM(IOPWM *ioPWM);

__declspec(dllimport) int GetIODI(IODI *ioDI);
__declspec(dllimport) int GetIOADC(IOADC *ioADC);

__declspec(dllimport) int SetEMotor(EMotor *eMotor, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int SetEMotorS(EMotorS *eMotorS, bool isQueued, uint64_t *queuedCmdIndex);

__declspec(dllimport) int SetColorSensor(bool enable, ColorPort colorPort, uint8_t version);
__declspec(dllimport) int GetColorSensor(uint8_t *r, uint8_t *g, uint8_t *b);

__declspec(dllimport) int SetInfraredSensor(bool enable, InfraredPort infraredPort, uint8_t version);
__declspec(dllimport) int GetInfraredSensor(InfraredPort port, uint8_t *value);

// CAL
__declspec(dllimport) int SetAngleSensorStaticError(float rearArmAngleError, float frontArmAngleError);
__declspec(dllimport) int GetAngleSensorStaticError(float *rearArmAngleError, float *frontArmAngleError);
__declspec(dllimport) int SetAngleSensorCoef(float rearArmAngleCoef, float frontArmAngleCoef);
__declspec(dllimport) int GetAngleSensorCoef(float *rearArmAngleCoef, float *frontArmAngleCoef);

__declspec(dllimport) int SetBaseDecoderStaticError(float baseDecoderError);
__declspec(dllimport) int GetBaseDecoderStaticError(float *baseDecoderError);

__declspec(dllimport) int SetLRHandCalibrateValue(float lrHandCalibrateValue);
__declspec(dllimport) int GetLRHandCalibrateValue(float *lrHandCalibrateValue);

// WIFI
__declspec(dllimport) int SetWIFIConfigMode(bool enable);
__declspec(dllimport) int GetWIFIConfigMode(bool *isEnabled);
__declspec(dllimport) int SetWIFISSID(const char *ssid);
__declspec(dllimport) int GetWIFISSID(char *ssid, uint32_t maxLen);
__declspec(dllimport) int SetWIFIPassword(const char *password);
__declspec(dllimport) int GetWIFIPassword(char *password, uint32_t maxLen);
__declspec(dllimport) int SetWIFIIPAddress(WIFIIPAddress *wifiIPAddress);
__declspec(dllimport) int GetWIFIIPAddress(WIFIIPAddress *wifiIPAddress);
__declspec(dllimport) int SetWIFINetmask(WIFINetmask *wifiNetmask);
__declspec(dllimport) int GetWIFINetmask(WIFINetmask *wifiNetmask);
__declspec(dllimport) int SetWIFIGateway(WIFIGateway *wifiGateway);
__declspec(dllimport) int GetWIFIGateway(WIFIGateway *wifiGateway);
__declspec(dllimport) int SetWIFIDNS(WIFIDNS *wifiDNS);
__declspec(dllimport) int GetWIFIDNS(WIFIDNS *wifiDNS);
__declspec(dllimport) int GetWIFIConnectStatus(bool *isConnected);

//FIRMWARE
__declspec(dllimport) int UpdateFirmware(FirmwareParams *firmwareParams);
__declspec(dllimport) int SetFirmwareMode(FirmwareMode *firmwareMode);
__declspec(dllimport) int GetFirmwareMode(FirmwareMode *firmwareMode);

//LOSTSTEP
__declspec(dllimport) int SetLostStepParams(float threshold, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int SetLostStepCmd(bool isQueued, uint64_t *queuedCmdIndex);

//UART4 Peripherals
__declspec(dllimport) int GetUART4PeripheralsType(uint8_t *type);
__declspec(dllimport) int SetUART4PeripheralsEnable(bool isEnable);
__declspec(dllimport) int GetUART4PeripheralsEnable(bool *isEnable);

//Function Pluse Mode
__declspec(dllimport) int SendPluse(PluseCmd *pluseCmd, bool isQueued, uint64_t *queuedCmdIndex);
__declspec(dllimport) int SendPluseEx(PluseCmd *pluseCmd);

// TEST
__declspec(dllimport) int GetUserParams(UserParams *userParams);
__declspec(dllimport) int GetPTPTime(PTPCmd *ptpCmd, uint32_t *ptpTime);

// Queued command
__declspec(dllimport) int SetQueuedCmdStartExec(void);
__declspec(dllimport) int SetQueuedCmdStopExec(void);
__declspec(dllimport) int SetQueuedCmdForceStopExec(void);
__declspec(dllimport) int SetQueuedCmdStartDownload(uint32_t totalLoop, uint32_t linePerLoop);
__declspec(dllimport) int SetQueuedCmdStopDownload(void);
__declspec(dllimport) int SetQueuedCmdClear(void);
__declspec(dllimport) int GetQueuedCmdCurrentIndex(uint64_t *queuedCmdCurrentIndex);
__declspec(dllimport) int GetQueuedCmdMotionFinish(bool *isFinish);
//parker add 设置debug输出使能
//__declspec(dllimport) bool SetDebugEnable(bool flag);
#endif // DOBOTDLL_H
