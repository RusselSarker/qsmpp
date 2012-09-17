#ifndef SMPP_DATA_SM_RESP_H
#define SMPP_DATA_SM_RESP_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class DataSmResp : public TlvsHeader {
  MessageId message_id;

public:
  const static int min_length = 17;

  DataSmResp();

  DataSmResp(const CommandStatus &command_status,
             const SequenceNumber &sequence_number,
             const MessageId &message_id);

  ~DataSmResp();

  //
  // Mutating
  //

  void setMessageId(const MessageId &p) {
    int diff = p.length() - message_id.length();
    message_id = p;
    Header::updateLength(diff);
  }

  void setMessageId(const char *p) {
    int diff = strlen(p) - message_id.length();
    message_id = p;
    Header::updateLength(diff);
  }

  //
  // Accessing
  //

  const MessageId &getMessageId() const { return message_id; }
};

} // namespace smpp

#endif // SMPP_DATA_SM_RESP_H
