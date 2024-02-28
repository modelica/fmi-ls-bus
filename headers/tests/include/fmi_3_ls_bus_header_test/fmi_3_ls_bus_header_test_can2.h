#include "../../fmi3LsBusCan2.h"
#include "../../fmi3LsBusUtil.h"
#include "../../fmi3LsBusUtilCan2.h"
#include <iostream>


/**
 * \brief Values that cause an overflow for the tested datatype.
 */
#define WRONG_U_INT82 256
#define WRONG_U_INT162 65536
#define WRONG_U_INT322 0x100000000

 /**
  * \brief Enum of the available operations by name.
  */
enum Operation2 { CanTransmit2, CanFdTransmit2, CanXlTransmit2, Confirm2, ConfigurationBaudrate2, ConfigurationFdBaudrate2, ConfigurationXlBaudrate2, ConfigurationArbitrationLostBehavior2, ArbitrationLost2, BusError2, Status2, Wakeup2, FormatError2 };

/**
 * \brief Checks if the CAN Transmit operation is created correctly by the corresponding macro.
 *
 * \param[in] id          The id of the CAN Transmit operation.
 * \param[in] ide         The ide of the CAN Transmit operation.
 * \param[in] rtr         The rtr of the CAN Transmit operation.
 * \param[in] data        The data of the CAN Transmit operation.
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckCanTransmitOperation2(long long int id, int ide, int rtr, fmi3UInt8 data[], bool correctData);

/**
 * \brief Checks if the CAN FD Transmit operation is created correctly by the corresponding macro.
 *
 * \param[in] id          The id of the CAN FD Transmit operation.
 * \param[in] ide         The ide of the Can FD Transmit operation.
 * \param[in] brs         The brs of the Can FD Transmit operation.
 * \param[in] esi         The rtr of the CAN FD Transmit operation.
 * \param[in] data        The data of the CAN FD Transmit operation.
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckCanFdTransmitOperation2(long long int id, int ide, int brs, int esi, fmi3UInt8 data[], bool correctData);

/**
 * \brief Checks if the CAN XL Transmit operation is created correctly by the corresponding macro.
 *
 * \param[in] id          The id of the CAN XL Transmit operation.
 * \param[in] ide         The ide of the CAN XL Transmit operation.
 * \param[in] sec         The sec of the CAN XL Transmit operation.
 * \param[in] sdt         The sdt of the CAN XL Transmit operation.
 * \param[in] vcid        The vcid of the CAN XL Transmit operation.
 * \param[in] af          The af of the CAN XL Transmit operation.
 * \param[in] data        The data of the CAN XL Transmit operation.
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckCanXlTransmitOperation2(long long int id, int ide, int sec, int sdt, int vcid, long long int af, fmi3UInt8 data[], bool correctData);

/**
 * \brief Checks if the Confirm operation is created correctly by the corresponding macro.
 *
 * \param[in] id          The id of the Confirm operation.
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckConfirmOperation2(long long int id, bool correctData);

/**
 * \brief Checks if the Configuration Baudrate operation is created correctly by the corresponding macro.
 *
 * \param[in] baudrate    The baud rate of the Configuration operation.
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckConfigurationBaudrateOperation2(long long int baudrate, bool correctData);

/**
 * \brief Checks if the Configuration FD Baudrate operation is created correctly by the corresponding macro.
 *
 * \param[in] baudrate    The baud rate of the Configuration operation.
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckConfigurationFdBaudrateOperation2(long long int baudrate, bool correctData);

/**
 * \brief Checks if the Configuration XL Baudrate operation is created correctly by the corresponding macro.
 *
 * \param[in] baudrate    The baud rate of the Configuration operation.
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckConfigurationXlBaudrateOperation2(long long int baudrate, bool correctData);

/**
 * \brief Checks if the Configuration Arbitration Lost Behavior operation is created correctly by the corresponding macro.
 *
 * \param[in] arbitrationLostBehavior    The arbitration lost behaviour of the Configuration operation.
 */
void CheckConfigurationArbitrationLostBehaviorOperation2(int arbitrationLostBehavior);

/**
 * \brief Checks if the Arbitration Lost Behavior operation is created correctly by the corresponding macro.
 *
 * \param[in] id          The id of the Arbitration Lost Behavior operation.
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckArbitrationLostBehaviorOperation2(long long int id, bool correctData);

/**
 * \brief Checks if the Bus Error operation is created correctly by the corresponding macro.
 *
 * \param[in] id          The id of the Bus Error operation.
 * \param[in] errorCode   The errorCode of the Bus Error operation.
 * \param[in] errorFlag   The errorFlag of the Bus Error operation.
 * \param[in] isSender    The attribute 'Is Sender' of the Bus Error operation.
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckBusErrorOperation2(long long int id, int errorCode, int errorFlag, fmi3UInt8 isSender, bool correctData);

/**
 * \brief Checks if the Status operation is created correctly by the corresponding macro.
 *
 * \param[in] status       The status of the Status operation.
 */
void CheckStatusOperation2(int status);

/**
 * \brief Checks if the WakeUp operation is created correctly by the corresponding macro.
 */
void CheckWakeupOperation2();

/**
 * \brief Checks if the Format Error operation is created correctly by the corresponding macro.
 *
 * \param[in] operationType  The type of operation of the Format Error operation.
 */
void CheckFormatErrorOperation2(Operation operationType);

/**
 * \brief Checks if the corresponding macro returns fmi3False if the data for creation is too big.
 *
 * \param[in] operation  The type of operation to be checked.
 */
void CheckDataSizeError2(Operation operation);

std::string sayHello2();

