#-------------------------------------------------
#
# Project created by QtCreator 2016-12-02T00:14:02
#
#-------------------------------------------------

QT       -= gui
QT       += av

TARGET = kynnaugh
TEMPLATE = lib

CONFIG += warn_off

DEFINES += KYNNAUGH_LIBRARY

INCLUDEPATH += $$PWD/generated
#INCLUDEPATH += /usr/include/Qt5GStreamer

LIBS += -lgrpc++
#LIBS += `PKG_CONFIG_PATH=/home/sean/dev/qt/5.6/gcc_64/lib/pkgconfig pkg-config --libs Qt5GStreamer-1.0`
#LIBS += `PKG_CONFIG_PATH=/home/sean/dev/qt/5.6/gcc_64/lib/pkgconfig pkg-config --libs Qt5GStreamerUtils-1.0`

#DEFINES += QT_NO_KEYWORDS

SOURCES += kynnaugh.cpp \
    sampledef.cpp \
    convert.cpp \
    speechrec.cpp

HEADERS += kynnaugh.h\
        kynnaugh_global.h \
    plugin_definitions.h \
    ts3_functions.h \
    teamspeak/clientlib_publicdefinitions.h \
    teamspeak/public_definitions.h \
    teamspeak/public_errors_rare.h \
    teamspeak/public_errors.h \
    teamspeak/public_rare_definitions.h \
    teamlog/logtypes.h \
    sampledef.h \
    convert.h \
    speechrec.h \
    generated/google/api/servicecontrol/v1/check_error.grpc.pb.h \
    generated/google/api/servicecontrol/v1/check_error.pb.h \
    generated/google/api/servicecontrol/v1/distribution.grpc.pb.h \
    generated/google/api/servicecontrol/v1/distribution.pb.h \
    generated/google/api/servicecontrol/v1/log_entry.grpc.pb.h \
    generated/google/api/servicecontrol/v1/log_entry.pb.h \
    generated/google/api/servicecontrol/v1/metric_value.grpc.pb.h \
    generated/google/api/servicecontrol/v1/metric_value.pb.h \
    generated/google/api/servicecontrol/v1/operation.grpc.pb.h \
    generated/google/api/servicecontrol/v1/operation.pb.h \
    generated/google/api/servicecontrol/v1/service_controller.grpc.pb.h \
    generated/google/api/servicecontrol/v1/service_controller.pb.h \
    generated/google/api/servicemanagement/v1/resources.grpc.pb.h \
    generated/google/api/servicemanagement/v1/resources.pb.h \
    generated/google/api/servicemanagement/v1/servicemanager.grpc.pb.h \
    generated/google/api/servicemanagement/v1/servicemanager.pb.h \
    generated/google/api/annotations.grpc.pb.h \
    generated/google/api/annotations.pb.h \
    generated/google/api/auth.grpc.pb.h \
    generated/google/api/auth.pb.h \
    generated/google/api/backend.grpc.pb.h \
    generated/google/api/backend.pb.h \
    generated/google/api/billing.grpc.pb.h \
    generated/google/api/billing.pb.h \
    generated/google/api/config_change.grpc.pb.h \
    generated/google/api/config_change.pb.h \
    generated/google/api/consumer.grpc.pb.h \
    generated/google/api/consumer.pb.h \
    generated/google/api/context.grpc.pb.h \
    generated/google/api/context.pb.h \
    generated/google/api/control.grpc.pb.h \
    generated/google/api/control.pb.h \
    generated/google/api/distribution.grpc.pb.h \
    generated/google/api/distribution.pb.h \
    generated/google/api/documentation.grpc.pb.h \
    generated/google/api/documentation.pb.h \
    generated/google/api/endpoint.grpc.pb.h \
    generated/google/api/endpoint.pb.h \
    generated/google/api/http.grpc.pb.h \
    generated/google/api/http.pb.h \
    generated/google/api/httpbody.grpc.pb.h \
    generated/google/api/httpbody.pb.h \
    generated/google/api/label.grpc.pb.h \
    generated/google/api/label.pb.h \
    generated/google/api/log.grpc.pb.h \
    generated/google/api/log.pb.h \
    generated/google/api/logging.grpc.pb.h \
    generated/google/api/logging.pb.h \
    generated/google/api/metric.grpc.pb.h \
    generated/google/api/metric.pb.h \
    generated/google/api/monitored_resource.grpc.pb.h \
    generated/google/api/monitored_resource.pb.h \
    generated/google/api/monitoring.grpc.pb.h \
    generated/google/api/monitoring.pb.h \
    generated/google/api/service.grpc.pb.h \
    generated/google/api/service.pb.h \
    generated/google/api/system_parameter.grpc.pb.h \
    generated/google/api/system_parameter.pb.h \
    generated/google/api/usage.grpc.pb.h \
    generated/google/api/usage.pb.h \
    generated/google/logging/type/http_request.grpc.pb.h \
    generated/google/logging/type/http_request.pb.h \
    generated/google/logging/type/log_severity.grpc.pb.h \
    generated/google/logging/type/log_severity.pb.h \
    generated/google/logging/v2/log_entry.grpc.pb.h \
    generated/google/logging/v2/log_entry.pb.h \
    generated/google/logging/v2/logging.grpc.pb.h \
    generated/google/logging/v2/logging.pb.h \
    generated/google/logging/v2/logging_config.grpc.pb.h \
    generated/google/logging/v2/logging_config.pb.h \
    generated/google/logging/v2/logging_metrics.grpc.pb.h \
    generated/google/logging/v2/logging_metrics.pb.h \
    generated/google/longrunning/operations.grpc.pb.h \
    generated/google/longrunning/operations.pb.h \
    generated/google/rpc/code.grpc.pb.h \
    generated/google/rpc/code.pb.h \
    generated/google/rpc/error_details.grpc.pb.h \
    generated/google/rpc/error_details.pb.h \
    generated/google/rpc/status.grpc.pb.h \
    generated/google/rpc/status.pb.h \
    generated/google/cloud/speech/v1beta1/cloud_speech.grpc.pb.h \
    generated/google/cloud/speech/v1beta1/cloud_speech.pb.h \
    generated/google/type/color.grpc.pb.h \
    generated/google/type/color.pb.h \
    generated/google/type/date.grpc.pb.h \
    generated/google/type/date.pb.h \
    generated/google/type/dayofweek.grpc.pb.h \
    generated/google/type/dayofweek.pb.h \
    generated/google/type/latlng.grpc.pb.h \
    generated/google/type/latlng.pb.h \
    generated/google/type/money.grpc.pb.h \
    generated/google/type/money.pb.h \
    generated/google/type/timeofday.grpc.pb.h \
    generated/google/type/timeofday.pb.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    generated/google/google/logging/README.md \
    generated/google/google/rpc/README.md \
    generated/google/type/README.md
