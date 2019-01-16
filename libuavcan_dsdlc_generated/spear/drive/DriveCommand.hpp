/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/spear/drive/20000.DriveCommand.uavcan
 */

#ifndef SPEAR_DRIVE_DRIVECOMMAND_HPP_INCLUDED
#define SPEAR_DRIVE_DRIVECOMMAND_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
#
# Command message for drive motors
#

# ID of wheel
uint3 wheel

# Speed to set wheel at (signed mm/s)
int13 speed
******************************************************************************/

/********************* DSDL signature source definition ***********************
spear.drive.DriveCommand
saturated uint3 wheel
saturated int13 speed
******************************************************************************/

#undef wheel
#undef speed

namespace spear
{
namespace drive
{

template <int _tmpl>
struct UAVCAN_EXPORT DriveCommand_
{
    typedef const DriveCommand_<_tmpl>& ParameterType;
    typedef DriveCommand_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
    };

    struct FieldTypes
    {
        typedef ::uavcan::IntegerSpec< 3, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > wheel;
        typedef ::uavcan::IntegerSpec< 13, ::uavcan::SignednessSigned, ::uavcan::CastModeSaturate > speed;
    };

    enum
    {
        MinBitLen
            = FieldTypes::wheel::MinBitLen
            + FieldTypes::speed::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::wheel::MaxBitLen
            + FieldTypes::speed::MaxBitLen
    };

    // Constants

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::wheel >::Type wheel;
    typename ::uavcan::StorageType< typename FieldTypes::speed >::Type speed;

    DriveCommand_()
        : wheel()
        , speed()
    {
        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<16 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    enum { DefaultDataTypeID = 20000 };

    static const char* getDataTypeFullName()
    {
        return "spear.drive.DriveCommand";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool DriveCommand_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        wheel == rhs.wheel &&
        speed == rhs.speed;
}

template <int _tmpl>
bool DriveCommand_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(wheel, rhs.wheel) &&
        ::uavcan::areClose(speed, rhs.speed);
}

template <int _tmpl>
int DriveCommand_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::wheel::encode(self.wheel, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::speed::encode(self.speed, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int DriveCommand_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::wheel::decode(self.wheel, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::speed::decode(self.speed, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature DriveCommand_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0xD8B5FC68C185F0F5ULL);

    FieldTypes::wheel::extendDataTypeSignature(signature);
    FieldTypes::speed::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

/*
 * Final typedef
 */
typedef DriveCommand_<0> DriveCommand;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::spear::drive::DriveCommand > _uavcan_gdtr_registrator_DriveCommand;

}

} // Namespace drive
} // Namespace spear

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::spear::drive::DriveCommand >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::spear::drive::DriveCommand::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::spear::drive::DriveCommand >::stream(Stream& s, ::spear::drive::DriveCommand::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "wheel: ";
    YamlStreamer< ::spear::drive::DriveCommand::FieldTypes::wheel >::stream(s, obj.wheel, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "speed: ";
    YamlStreamer< ::spear::drive::DriveCommand::FieldTypes::speed >::stream(s, obj.speed, level + 1);
}

}

namespace spear
{
namespace drive
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::spear::drive::DriveCommand::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::spear::drive::DriveCommand >::stream(s, obj, 0);
    return s;
}

} // Namespace drive
} // Namespace spear

#endif // SPEAR_DRIVE_DRIVECOMMAND_HPP_INCLUDED