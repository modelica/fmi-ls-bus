#ifndef fmi3LsBusEthernet_h
#define fmi3LsBusEthernet_h

#include "fmi3LsBus.h"
#include "fmi3PlatformTypes.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4200)
#pragma warning(disable : 4815)
#endif

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * \defgroup FMI3_LS_BUS_ETHERNET_OPERATION_CODES Ethernet bus-specific operation codes
 * \brief Operation codes for Ethernet-specific bus operations.
 * \{
 */

/**
 * \brief FMI virtual bus operation of type 'Transmit'.
 *
 * Indicates the transmission of an Ethernet frame or mPacket.
 */
#define FMI3_LS_BUS_ETHERNET_OP_TRANSMIT ((fmi3LsBusOperationCode)0x10)

/**
 * \brief FMI virtual bus operation of type 'Confirm'.
 *
 * Indicates the successful transmission of an Ethernet frame.
 */
#define FMI3_LS_BUS_ETHERNET_OP_CONFIRM ((fmi3LsBusOperationCode)0x20)

/**
 * \brief FMI virtual bus operation of type 'Bus Error'.
 *
 * Indicates an error during the transmission of an Ethernet frame.
 */
#define FMI3_LS_BUS_ETHERNET_OP_BUS_ERROR ((fmi3LsBusOperationCode)0x30)

/**
 * \brief FMI virtual bus operation of type 'Configuration'.
 *
 * Provides information to configure the Ethernet bus.
 */
#define FMI3_LS_BUS_ETHERNET_OP_CONFIGURATION ((fmi3LsBusOperationCode)0x40)

/**
 * \brief FMI virtual bus operation of type 'Wakeup'.
 *
 * Indicates a wakeup.
 */
#define FMI3_LS_BUS_ETHERNET_OP_WAKEUP ((fmi3LsBusOperationCode)0x41)

/** \} */

#pragma pack(1)

/**
 * \defgroup FMI3_LS_BUS_ETHERNET_DATA_TYPES Ethernet-specific data types
 * \brief Data types used for Ethernet.
 * \{
 */

/**
 * \brief Data type representing an octet of the MAC address.
 */
typedef fmi3UInt8 fmi3LsBusEthernetMacAddressOctet;

/**
 * \brief Data type representing the EtherType or frame length.
 */
typedef fmi3UInt16 fmi3LsBusEthernetEtherTypeOrLength;

/**
 * \brief Data type representing the Ethernet frame payload data.
 */
typedef fmi3UInt8 fmi3LsBusEthernetData;

/**
 * \brief Data type representing the Ethernet frame payload length.
 */
typedef fmi3UInt8 fmi3LsBusEthernetDataLength;

/**
 * \brief Data type representing a CRC checksum.
 */
typedef fmi3UInt32 fmi3LsBusEthernetCRC;

/**
 * \brief Data type representing an "Start frame delimiter" (SFD) or "Start mPacket delimiter" (SMD).
 */
typedef fmi3UInt8 fmi3LsBusEthernetStartDelimiter;

/**
 * \brief Data type representing the fragment counter of an mPacket.
 */
typedef fmi3UInt8 fmi3LsBusEthernetMPacketFragmentCounter;

/**
 * \brief Data type representing the parameter configured with a configuration operation.
 */
typedef fmi3UInt8 fmi3LsBusEthernetConfigParameterType;

/**
 * \brief Indicates the supported Ethernet PHYs of this node.
 */
#define FMI3_LS_BUS_ETHERNET_CONFIG_PARAMETER_TYPE_SUPPORTED_PHY_TYPES ((fmi3LsBusEthernetConfigParameterType)0x0)

/**
 * \brief The length of the list of supported PHY types.
 */
typedef fmi3UInt16 fmi3LsBusEthernetPhyTypeLength;

/**
 * \brief Data type representing a character.
 */
typedef fmi3Char fmi3LsBusEthernetPhyTypeCharacter;

/**
 * \brief Indicates whether the node media-dependent interface of the node is wired in a crossover configuration.
 */
typedef fmi3UInt8 fmi3LsBusEthernetMdiMode;

/**
 * \brief Not applicable
 */
#define FMI3_LS_BUS_ETHERNET_MDI_MODE_NONE ((fmi3LsBusEthernetMdiMode)0x0)
/**
 * \brief The MDI is wired in normal configuration.
 */
#define FMI3_LS_BUS_ETHERNET_MDI_MODE_MDI ((fmi3LsBusEthernetMdiMode)0x1)
/**
 * \brief The MDI is wired in crossover configuration.
 */
#define FMI3_LS_BUS_ETHERNET_MDI_MODE_MDI_X ((fmi3LsBusEthernetMdiMode)0x2)
/**
 * \brief The node supports auto MDI/MDI-X.
 */
#define FMI3_LS_BUS_ETHERNET_MDI_MODE_AUTO_MDI_X ((fmi3LsBusEthernetMdiMode)0x3)

/**
 * \brief Configuration data sent with 'Configuration' operation of type 'SUPPORTED_PHY_TYPES'. This configuration opeation serves to check the compatibility on the physical layer.
 */
typedef struct
{
    fmi3LsBusEthernetMdiMode mdiMode;  /**< The configuration of the node's media-dependent interface */
    fmi3LsBusEthernetDataLength numberOfSupportedPhyTypes;  /**< The number of characters in the list of supported PHY types */
    fmi3LsBusEthernetPhyTypeCharacter supportedPhyTypes;  /**< An array of zero-terminated strings describing PHY types supported by this Ethernet node  The first element in this list indicates the type of PHY used by this node  The list must have at least one element  Elements describing a PHY standardized by 8023 or an amendment must use the value described in the chapter "303212 aPhyType" of the standard  Otherwise, a vendor-defined value may be used */
} fmi3LsBusEthernetConfigurationSupportedPhyTypes;

/**
 * \brief Indicates the type of a bus error.
 */
typedef fmi3UInt8 fmi3LsBusEthernetBusErrorCode;

/**
 * \brief Unknown error.
 */
#define FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_UNKNOWN ((fmi3LsBusEthernetBusErrorCode)0x0)
/**
 * \brief The medium is currently busy.
 */
#define FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_MEDIUM_BUSY ((fmi3LsBusEthernetBusErrorCode)0x1)
/**
 * \brief A frame collided during transmission.
 */
#define FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_COLLISION ((fmi3LsBusEthernetBusErrorCode)0x2)

/** \} */

/**
 * \defgroup FMI3_LS_BUS_ETHERNET_OPERATION_TYPES Ethernet-specific operation types
 * \brief Operations used for Ethernet.
 * \{
 */

/**
 * \brief Indicates the transmission of an Ethernet frame or mPacket.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                          /**< Operation header */
    fmi3LsBusEthernetStartDelimiter startDelimiter;           /**< The start frame (SFD) or start mPacket (SMD) delimiter  Always set to 0xD5 for ordinary Ethernet frames when not using preemption/fragmentation */
    fmi3LsBusEthernetMPacketFragmentCounter fragmentCounter;  /**< Fragment counter of the continuation mPacket  Must be set to 0, if this is not a continuation mPacket */
    fmi3LsBusBoolean lastFragment;                            /**< Indicates whether this is the last fragment of a fragmented Ethernet frame  Must be set to `TRUE` if this is a full Ethernet frame */
    fmi3LsBusEthernetMacAddressOctet destinationAddress[6];   /**< The destination address of the frame  Only applicable if this is a full Ethernet frame or the first fragment of an Ethernet frame */
    fmi3LsBusEthernetMacAddressOctet sourceAddress[6];        /**< The destination address of the frame  Only applicable if this is a full Ethernet frame or the first fragment of an Ethernet frame */
    fmi3LsBusEthernetEtherTypeOrLength etherTypeOrLength;     /**< Indicates the type of Ethernet frame (Ethernet II) or frame length (8023) */
    fmi3LsBusEthernetDataLength dataLength;                   /**< The length of the data of this Ethernet frame or mPacket  Note that this does not correspond to a field in the Ethernet frame */
    fmi3LsBusEthernetData data[];                             /**< The payload data of the Ethernet frame or mPacket */
} fmi3LsBusEthernetOperationTransmit;

/**
 * \brief Indicates the successful transmission of an Ethernet frame.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;  /**< Operation header */
} fmi3LsBusEthernetOperationConfirm;

/**
 * \brief Indicates an error during the transmission of an Ethernet frame.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;          /**< Operation header */
    fmi3LsBusEthernetBusErrorCode errorCode;  /**< Represents the specified bus error to simulate */
    fmi3LsBusBoolean isSender;                /**< Indicates whether this bus error occurs in response to a transmission of this FMU */
} fmi3LsBusEthernetOperationBusError;

/**
 * \brief Provides information to configure the Ethernet bus.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                                        /**< Operation header */
    fmi3LsBusEthernetConfigParameterType parameterType;                     /**< Defines the current configuration parameter */
    union
    {
        fmi3LsBusEthernetConfigurationSupportedPhyTypes supportedPhyTypes;  /**< Configuration data for parameter 'SUPPORTED_PHY_TYPES'. */
    };
} fmi3LsBusEthernetOperationConfiguration;

/**
 * \brief Indicates a wakeup.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;  /**< Operation header */
} fmi3LsBusEthernetOperationWakeup;

/** \} */

#pragma pack()

#ifdef __cplusplus
} /* end of extern "C" { */
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif /* fmi3LsBusEthernet_h */