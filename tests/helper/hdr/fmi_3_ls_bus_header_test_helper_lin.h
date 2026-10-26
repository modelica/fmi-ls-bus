#include "fmi3LsBusLin.h"
#include "fmi3LsBusUtil.h"
#include "fmi3LsBusUtilLin.h"

enum LinOperation { LinTransmit, LinConfirm, LinBusError, LinConfiguration, LinWakeup };

void CheckLinTransmitOperation(int framePart, int id, int checksumType, size_t dataSize, fmi3UInt8 data[], bool correctData);
void CheckLinConfirmOperation(int id, bool correctData);
void CheckLinBusErrorOperation(int id, int errorCode, bool correctData);
void CheckLinConfigurationBaudrateOperation(unsigned long long int baudrate, bool correctData);
void CheckLinConfigurationNodeTypeOperation(int nodeType);
void CheckLinWakeupOperation();
void CheckLinDataSizeError(LinOperation operation);