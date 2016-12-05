#ifndef SPEECHREC_H
#define SPEECHREC_H

#include <google/cloud/speech/v1beta1/cloud_speech.pb.h>
#include <google/cloud/speech/v1beta1/cloud_speech.grpc.pb.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include <grpc++/support/status.h>
#include <grpc/grpc.h>
#include <QString>

class speechrec
{
public:
    explicit speechrec();
    QString recognize(char* buf, size_t length);

private:
    std::unique_ptr<google::cloud::speech::v1beta1::Speech::Stub> stub;
    ::grpc::ClientContext ctx;
    bool configSubmitted;
    bool setupConfig();

};

#endif // SPEECHREC_H
