#include "fmi3LsBusCan2.h"
#include "fmi3LsBusUtil.h"
#include "fmi3LsBusUtilCan2.h"
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