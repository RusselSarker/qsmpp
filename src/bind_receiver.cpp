#include <bind_receiver.h>

namespace smpp {

BindReceiver::BindReceiver() :
  Header(CommandLength(min_length),
         CommandId(CommandId::BindReceiver),
         CommandStatus(CommandStatus::ESME_ROK),
         SequenceNumber::Min) {

}

BindReceiver::BindReceiver(const SequenceNumber &sequence_number,
                           const SystemId &system_id,
                           const Password &password,
                           const SystemType &system_type,
                           const InterfaceVersion &interface_version,
                           const Ton &addr_ton,
                           const Npi &addr_npi,
                           const AddressRange &address_range) :
    Header(CommandLength(min_length),
           CommandId(CommandId::BindReceiver),
           CommandStatus(CommandStatus::ESME_ROK),
           sequence_number),
    system_id(system_id),
    password(password),
    system_type(system_type),
    interface_version(interface_version),
    addr_ton(addr_ton),
    addr_npi(addr_npi),
    address_range(address_range) {
  Header::updateLength(system_id.length() +
                       password.length() +
                       system_type.length() +
                       address_range.length());
}

BindReceiver::~BindReceiver() {

}

} // namespace smpp
