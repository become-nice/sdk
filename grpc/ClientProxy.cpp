// Copyright (C) 2019-2020 Zilliz. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance
// with the License. You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied. See the License for the specific language governing permissions and limitations under the License.

#include "grpc/ClientProxy.h"
#include "thirdparty/nlohmann/json.hpp"

#include <memory>
#include <string>
#include <vector>

#include "grpc-gen/gen-milvus/milvus.grpc.pb.h"

#define MILVUS_SDK_VERSION "0.9.0";

namespace milvus {

using JSON = nlohmann::json;
using byte = uint8_t;
static const char* EXTRA_PARAM_KEY = "params";

bool
UriCheck(const std::string& uri) {
    size_t index = uri.find_first_of(':', 0);
    return (index != std::string::npos);
}

template <typename T>
void
ConstructSearchParam(const std::string& collection_name, const std::vector<std::string>& partition_tag_array,
                     int64_t topk, const std::string& extra_params, T& search_param) {
//    search_param.set_collection_name(collection_name);
//    milvus::grpc::KeyValuePair* kv = search_param.add_extra_params();
//    kv->set_key(EXTRA_PARAM_KEY);
//    kv->set_value(extra_params);
//
//    for (auto& tag : partition_tag_array) {
//        search_param.add_partition_tag_array(tag);
//    }
}

void
CopyRowRecord(::milvus::grpc::VectorRowRecord* target, const VectorData& src) {
//    if (!src.float_data.empty()) {
//        auto vector_data = target->mutable_float_data();
//        vector_data->Resize(static_cast<int>(src.float_data.size()), 0.0);
//        memcpy(vector_data->mutable_data(), src.float_data.data(), src.float_data.size() * sizeof(float));
//    }
//
//    if (!src.binary_data.empty()) {
//        target->set_binary_data(src.binary_data.data(), src.binary_data.size());
//    }
}

void
ConstructTopkResult(const ::milvus::grpc::QueryResult& grpc_result, TopKQueryResult& topk_query_result) {
//    topk_query_result.reserve(grpc_result.row_num());
//    int64_t nq = grpc_result.row_num();
//    int64_t topk = grpc_result.entities().ids_size() / nq;
//    for (int64_t i = 0; i < nq; i++) {
//        milvus::QueryResult one_result;
//        one_result.ids.resize(topk);
//        one_result.distances.resize(topk);
//        memcpy(one_result.ids.data(), grpc_result.entities().ids().data() + topk * i, topk * sizeof(int64_t));
//        memcpy(one_result.distances.data(), grpc_result.distances().data() + topk * i, topk * sizeof(float));
//
//        int valid_size = one_result.ids.size();
//        while (valid_size > 0 && one_result.ids[valid_size - 1] == -1) {
//            valid_size--;
//        }
//        if (valid_size != topk) {
//            one_result.ids.resize(valid_size);
//            one_result.distances.resize(valid_size);
//        }
//
//        topk_query_result.emplace_back(one_result);
//    }
}

void
ConstructTopkQueryResult(const ::milvus::grpc::QueryResult& grpc_result, TopKQueryResult& topk_query_result) {
//    int64_t nq = grpc_result.row_num();
//    if (nq == 0) {
//        return;
//    }
//    topk_query_result.reserve(nq);
//
//    auto grpc_entity = grpc_result.entities();
//    int64_t topk = grpc_entity.ids_size() / nq;
//    // TODO(yukun): filter -1 results
//    for (int64_t i = 0; i < grpc_result.row_num(); i++) {
//        milvus::QueryResult one_result;
//        one_result.ids.resize(topk);
//        one_result.distances.resize(topk);
//        memcpy(one_result.ids.data(), grpc_entity.ids().data() + topk * i, topk * sizeof(int64_t));
//        memcpy(one_result.distances.data(), grpc_result.distances().data() + topk * i, topk * sizeof(float));
//        int64_t j;
//        for (j = 0; j < grpc_entity.fields_size(); j++) {
//            auto grpc_field = grpc_entity.fields(j);
//            if (grpc_field.has_attr_record()) {
//                if (grpc_field.attr_record().int32_value_size() > 0) {
//                    std::vector<int32_t> int32_data(topk);
//                    memcpy(int32_data.data(), grpc_field.attr_record().int32_value().data() + topk * i,
//                           topk * sizeof(int32_t));
//
//                    one_result.field_value.int32_value.insert(std::make_pair(grpc_field.field_name(), int32_data));
//                } else if (grpc_field.attr_record().int64_value_size() > 0) {
//                    std::vector<int64_t> int64_data(topk);
//                    memcpy(int64_data.data(), grpc_field.attr_record().int64_value().data() + topk * i,
//                           topk * sizeof(int64_t));
//                    one_result.field_value.int64_value.insert(std::make_pair(grpc_field.field_name(), int64_data));
//                } else if (grpc_field.attr_record().float_value_size() > 0) {
//                    std::vector<float> float_data(topk);
//                    memcpy(float_data.data(), grpc_field.attr_record().float_value().data() + topk * i,
//                           topk * sizeof(float));
//                    one_result.field_value.float_value.insert(std::make_pair(grpc_field.field_name(), float_data));
//                } else if (grpc_field.attr_record().double_value_size() > 0) {
//                    std::vector<double> double_data(topk);
//                    memcpy(double_data.data(), grpc_field.attr_record().double_value().data() + topk * i,
//                           topk * sizeof(double));
//                    one_result.field_value.double_value.insert(std::make_pair(grpc_field.field_name(), double_data));
//                }
//            }
//            if (grpc_field.has_vector_record()) {
//                int64_t vector_row_count = grpc_field.vector_record().records_size();
//                if (vector_row_count > 0) {
//                    std::vector<VectorData> vector_data(topk);
//                    for (int64_t k = topk * i; k < topk * (i + 1); k++) {
//                        auto grpc_vector_data = grpc_field.vector_record().records(k);
//                        if (grpc_vector_data.float_data_size() > 0) {
//                            vector_data[k].float_data.resize(grpc_vector_data.float_data_size());
//                            memcpy(vector_data[k].float_data.data(), grpc_vector_data.float_data().data(),
//                                   grpc_vector_data.float_data_size() * sizeof(float));
//                        } else if (grpc_vector_data.binary_data().size() > 0) {
//                            vector_data[k].binary_data.resize(grpc_vector_data.binary_data().size() / 8);
//                            memcpy(vector_data[k].binary_data.data(), grpc_vector_data.binary_data().data(),
//                                   grpc_vector_data.binary_data().size());
//                        }
//                    }
//                    one_result.field_value.vector_value.insert(std::make_pair(grpc_field.field_name(), vector_data));
//                }
//            }
//        }
//        topk_query_result.emplace_back(one_result);
//    }
}

void
CopyFieldValue(const FieldValue &field_value, milvus::grpc::InsertParam &insert_param) {
    std::vector<std::vector<byte>> binary_data(field_value.row_num);
    if (!field_value.int8_value.empty()) {
        for (auto &field_it : field_value.int8_value) {
            auto grpc_field = insert_param.mutable_schema()->add_field_metas();
            grpc_field->set_field_name(field_it.first);
            grpc_field->set_type(milvus::grpc::DataType::INT8);
            grpc_field->set_dim(1);
            auto field_data = field_it.second;
            auto data_size = field_data.size();
            for (int i = 0; i < data_size; i++) {
                binary_data[i].push_back(field_data[i]);
            }
        }
    }
    if (!field_value.int16_value.empty()) {
        for (auto &field_it : field_value.int16_value) {
            auto grpc_field = insert_param.mutable_schema()->add_field_metas();
            grpc_field->set_field_name(field_it.first);
            grpc_field->set_type(milvus::grpc::DataType::INT16);
            grpc_field->set_dim(1);
            auto field_data = field_it.second;
            auto data_size = field_data.size();
            for (int i = 0; i < data_size; i++) {
                const byte *begin = reinterpret_cast< const byte * >( &field_data[i]);
                const byte *end = begin + sizeof(int16_t);
                binary_data[i].insert(std::end(binary_data[i]), begin, end);
            }
        }
    }
    if (!field_value.int32_value.empty()) {
        for (auto &field_it : field_value.int32_value) {
            auto grpc_field = insert_param.mutable_schema()->add_field_metas();
            grpc_field->set_field_name(field_it.first);
            grpc_field->set_type(milvus::grpc::DataType::INT32);
            grpc_field->set_dim(1);
            auto field_data = field_it.second;
            auto data_size = field_data.size();
            for (int i = 0; i < data_size; i++) {
                const byte *begin = reinterpret_cast< const byte * >( &field_data[i]);
                const byte *end = begin + sizeof(int32_t);
                binary_data[i].insert(std::end(binary_data[i]), begin, end);
            }
        }
    }
    if (!field_value.int64_value.empty()) {
        for (auto &field_it : field_value.int64_value) {
            auto grpc_field = insert_param.mutable_schema()->add_field_metas();
            grpc_field->set_field_name(field_it.first);
            grpc_field->set_type(milvus::grpc::DataType::INT64);
            grpc_field->set_dim(1);
            auto field_data = field_it.second;
            auto data_size = field_data.size();
            for (int i = 0; i < data_size; i++) {
                const byte *begin = reinterpret_cast< const byte * >( &field_data[i]);
                const byte *end = begin + sizeof(int64_t);
                binary_data[i].insert(std::end(binary_data[i]), begin, end);
            }
        }
    }
    if (!field_value.float_value.empty()) {
        for (auto &field_it : field_value.float_value) {
            auto grpc_field = insert_param.mutable_schema()->add_field_metas();
            grpc_field->set_field_name(field_it.first);
            grpc_field->set_type(milvus::grpc::DataType::FLOAT);
            grpc_field->set_dim(1);
            auto field_data = field_it.second;
            auto data_size = field_data.size();
            for (int i = 0; i < data_size; i++) {
                const byte *begin = reinterpret_cast< const byte * >( &field_data[i]);
                const byte *end = begin + sizeof(float);
                binary_data[i].insert(std::end(binary_data[i]), begin, end);
            }
        }
    }
    if (!field_value.double_value.empty()) {
        for (auto &field_it : field_value.double_value) {
            auto grpc_field = insert_param.mutable_schema()->add_field_metas();
            grpc_field->set_field_name(field_it.first);
            grpc_field->set_type(milvus::grpc::DataType::DOUBLE);
            grpc_field->set_dim(1);
            auto field_data = field_it.second;
            auto data_size = field_data.size();
            for (int i = 0; i < data_size; i++) {
                const byte *begin = reinterpret_cast< const byte * >( &field_data[i]);
                const byte *end = begin + sizeof(double);
                binary_data[i].insert(std::end(binary_data[i]), begin, end);
            }
        }
    }
    if (!field_value.vector_value.empty()) {
        for (auto &field_it : field_value.vector_value) {
            auto grpc_field = insert_param.mutable_schema()->add_field_metas();
            grpc_field->set_field_name(field_it.first);
            auto field_data = field_it.second;
            auto data_size = field_data.size();
            if (field_data[0].binary_data.empty()) {
                grpc_field->set_type(milvus::grpc::DataType::VECTOR_FLOAT);
                grpc_field->set_dim(field_data[0].float_data.size());
                for (int i = 0; i < data_size; i++) {
                    const byte *begin = reinterpret_cast< const byte * >( field_data[i].float_data.data());
                    const byte *end = begin + sizeof(float) * (field_data[i].float_data.size());
                    binary_data[i].insert(std::end(binary_data[i]), begin, end);
                }
            } else {
                grpc_field->set_type(milvus::grpc::DataType::VECTOR_BINARY);
                grpc_field->set_dim(field_data[0].binary_data.size() / sizeof(float));
                for (int i = 0; i < data_size; i++) {
                    binary_data[i].insert(std::end(binary_data[i]), field_data[i].binary_data.data(),
                                          field_data[i].binary_data.data() + field_data[i].binary_data.size());
                }
            }
        }
    }
    for (int i = 0; i < binary_data.size(); i++) {
        auto row = insert_param.add_rows_data();
        row->set_blob(reinterpret_cast<const char *>(binary_data[i].data()), binary_data[i].size());
    }
}

void
CopyEntityToJson(::milvus::grpc::Entities& grpc_entities, JSON& json_entity,Mapping schema) {
    auto rows = grpc_entities.rows_data();
    auto row_num = grpc_entities.ids().size();
    FieldValue data_value;
    data_value.row_num = rows.size();
    std::vector<std::string> field_names(schema.fields.size());
    for (int i = 0; i < schema.fields.size(); i++) {
        field_names[i] = schema.fields[i]->field_name;
    }

    for (int i = 0; i < row_num; i++) {
        auto row = rows[i].blob();
        int32_t offset = 0;
        for (int j = 0; j < schema.fields.size(); j++) {
            switch (schema.fields[j]->field_type) {
                case DataType::BOOL:
                case DataType::INT8 :{
                    data_value.int8_value[schema.fields[j]->field_name].push_back(row[offset]);
                    offset += 1;
                    break;
                }
                case DataType::INT16:{
                    auto int16_ptr = reinterpret_cast<const int16_t *>(row.data() + offset);
                    data_value.int16_value[schema.fields[j]->field_name].push_back(int16_ptr[0]);
                    offset += 2;
                    break;
                }
                case DataType::INT32:{
                    auto int32_ptr = reinterpret_cast<const int32_t *>(row.data() + offset);
                    data_value.int32_value[schema.fields[j]->field_name].push_back(int32_ptr[0]);
                    offset += 4;
                    break;
                }
                case DataType::INT64:{
                    auto int64_ptr = reinterpret_cast<const int32_t *>(row.data() + offset);
                    data_value.int64_value[schema.fields[j]->field_name].push_back(int64_ptr[0]);
                    offset += 8;
                    break;
                }
                case DataType::FLOAT:{
                    auto float_ptr = reinterpret_cast<const float *>(row.data() + offset);
                    data_value.float_value[schema.fields[j]->field_name].push_back(float_ptr[0]);
                    offset += sizeof(float);
                    break;
                }
                case DataType::DOUBLE:{
                    auto double_ptr = reinterpret_cast<const float *>(row.data() + offset);
                    data_value.float_value[schema.fields[j]->field_name].push_back(double_ptr[0]);
                    offset += sizeof(double);
                    break;
                }
                case DataType::VECTOR_BINARY:{
                    const byte *begin = reinterpret_cast< const byte * >( rows.data()) + offset;
                    const byte *end = begin + schema.fields[j]->dim;
                    data_value.vector_value[schema.fields[j]->field_name][i].binary_data.insert(
                            std::end(data_value.vector_value[schema.fields[j]->field_name][i].binary_data),
                            begin,
                            end);
                    offset += schema.fields[j]->dim;
                }
                case DataType::VECTOR_FLOAT: {
                    const float *begin = reinterpret_cast< const float * >( rows.data()) + offset;
                    const float *end = begin + schema.fields[j]->dim;
                    data_value.vector_value[schema.fields[j]->field_name][i].float_data.insert(
                            std::end(data_value.vector_value[schema.fields[j]->field_name][i].float_data),
                            begin,
                            end);
                    offset += schema.fields[j]->dim * sizeof(float);
                    break;
                }
                default:
                    break;
            }
        }
    }

    for (int i = 0; i < row_num; i++) {
        JSON one_json;
        one_json["id"] = grpc_entities.ids(i);
        if (grpc_entities.valid_row(i)) {
            for (const auto& name : field_names) {
                if (data_value.int8_value.find(name) != data_value.int8_value.end()) {
                    one_json[name] = data_value.int8_value.at(name)[i];
                } else if (data_value.int16_value.find(name) != data_value.int16_value.end()){
                    one_json[name] = data_value.int16_value.at(name)[i];
                } else if (data_value.int32_value.find(name) != data_value.int32_value.end()) {
                    one_json[name] = data_value.int32_value.at(name)[i];
                } else if (data_value.int64_value.find(name) != data_value.int64_value.end()) {
                    one_json[name] = data_value.int64_value.at(name)[i];
                } else if (data_value.float_value.find(name) != data_value.float_value.end()) {
                    one_json[name] = data_value.float_value.at(name)[i];
                } else if (data_value.double_value.find(name) != data_value.double_value.end()) {
                    one_json[name] = data_value.double_value.at(name)[i];
                } else if (data_value.vector_value.find(name) != data_value.vector_value.end()) {
                    if (!(data_value.vector_value.at(name)[i].float_data.empty())) {
                        one_json[name] = data_value.vector_value.at(name)[i].float_data;
                    } else if (!(data_value.vector_value.at(name)[i].binary_data.empty())) {
                        one_json[name] = data_value.vector_value.at(name)[i].binary_data;
                    }
                }
            }
        }
        json_entity.emplace_back(one_json);
    }
}

Status
ClientProxy::Connect(const ConnectParam& param) {
    std::string uri = param.ip_address + ":" + param.port;

    ::grpc::ChannelArguments args;
    args.SetMaxSendMessageSize(-1);
    args.SetMaxReceiveMessageSize(-1);
    channel_ = ::grpc::CreateCustomChannel(uri, ::grpc::InsecureChannelCredentials(), args);
    if (channel_ != nullptr) {
        connected_ = true;
        client_ptr_ = std::make_shared<GrpcClient>(channel_);
        return Status::OK();
    }

    std::string reason = "Connect failed!";
    connected_ = false;
    return Status(StatusCode::NotConnected, reason);
}

Status
ClientProxy::Connect(const std::string& uri) {
    if (!UriCheck(uri)) {
        return Status(StatusCode::InvalidAgument, "Invalid uri");
    }
    size_t index = uri.find_first_of(':', 0);

    ConnectParam param;
    param.ip_address = uri.substr(0, index);
    param.port = uri.substr(index + 1);

    return Connect(param);
}

Status
ClientProxy::Connected() const {
    try {
        std::string info;
        return client_ptr_->Cmd("", info);
    } catch (std::exception& ex) {
        return Status(StatusCode::NotConnected, "Connection lost: " + std::string(ex.what()));
    }
}

Status
ClientProxy::Disconnect() {
    try {
        Status status = client_ptr_->Disconnect();
        connected_ = false;
        channel_.reset();
        return status;
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to disconnect: " + std::string(ex.what()));
    }
}

Status
ClientProxy::CreateCollection(const Mapping& mapping, const std::string& extra_params) {
    try {
//        ::milvus::grpc::Mapping grpc_mapping;
//        grpc_mapping.set_collection_name(mapping.collection_name);
//        for (auto& field : mapping.fields) {
//            auto grpc_field = grpc_mapping.add_fields();
//            grpc_field->set_name(field->field_name);
//            grpc_field->set_type((::milvus::grpc::DataType)field->field_type);
//            JSON json_index_param = JSON::parse(field->index_params);
//            for (auto& json_param : json_index_param.items()) {
//                auto grpc_index_param = grpc_field->add_index_params();
//                grpc_index_param->set_key(json_param.key());
//                grpc_index_param->set_value(json_param.value());
//            }
//
//            auto grpc_extra_param = grpc_field->add_extra_params();
//            grpc_extra_param->set_key(EXTRA_PARAM_KEY);
//            grpc_extra_param->set_value(field->extra_params);
//        }
//        auto grpc_param = grpc_mapping.add_extra_params();
//        grpc_param->set_key(EXTRA_PARAM_KEY);
//        grpc_param->set_value(extra_params);

//        return client_ptr_->CreateCollection(grpc_mapping);
          return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to create collection: " + std::string(ex.what()));
    }
}

Status
ClientProxy::DropCollection(const std::string& collection_name) {
    try {
//        ::milvus::grpc::CollectionName grpc_collection_name;
//        grpc_collection_name.set_collection_name(collection_name);
//        return client_ptr_->DropCollection(grpc_collection_name);
          return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to drop collection: " + std::string(ex.what()));
    }
}

bool
ClientProxy::HasCollection(const std::string& collection_name) {
    try {
//        Status status = Status::OK();
//        ::milvus::grpc::CollectionName grpc_collection_name;
//        grpc_collection_name.set_collection_name(collection_name);
//        return client_ptr_->HasCollection(grpc_collection_name, status);
          return true;
    } catch (std::exception& ex) {
        return false;
    }
}

Status
ClientProxy::ListCollections(std::vector<std::string>& collection_array) {
    try {
//        Status status;
//        milvus::grpc::CollectionNameList collection_name_list;
//        status = client_ptr_->ListCollections(collection_name_list);
//
//        collection_array.resize(collection_name_list.collection_names_size());
//        for (uint64_t i = 0; i < collection_name_list.collection_names_size(); ++i) {
//            collection_array[i] = collection_name_list.collection_names(i);
//        }
        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to list collections: " + std::string(ex.what()));
    }
}

Status
ClientProxy::GetCollectionInfo(const std::string& collection_name, Mapping& mapping) {
    try {
        ::milvus::grpc::Mapping grpc_mapping;

        Status status = client_ptr_->GetCollectionInfo(collection_name, grpc_mapping);

        mapping.collection_name = collection_name;
        for (int64_t i = 0; i < grpc_mapping.schema().field_metas().size(); i++) {
            auto grpc_field = grpc_mapping.schema().field_metas()[i];
            FieldPtr field_ptr = std::make_shared<Field>();
            field_ptr->field_name = grpc_field.field_name();
            field_ptr->field_type = (DataType)grpc_field.type();
            field_ptr->dim = grpc_field.dim();
            mapping.fields.emplace_back(field_ptr);
        }
        return status;
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to get collection info: " + std::string(ex.what()));
    }
}

Status
ClientProxy::GetCollectionStats(const std::string& collection_name, std::string& collection_stats) {
    try {
//        Status status;
//        ::milvus::grpc::CollectionName grpc_collection_name;
//        grpc_collection_name.set_collection_name(collection_name);
//        milvus::grpc::CollectionInfo grpc_collection_stats;
//        status = client_ptr_->GetCollectionStats(grpc_collection_name, grpc_collection_stats);
//
//        collection_stats = grpc_collection_stats.json_info();

        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to get collection stats: " + std::string(ex.what()));
    }
}

Status
ClientProxy::CountEntities(const std::string& collection_name, int64_t& row_count) {
    try {
//        Status status;
//        ::milvus::grpc::CollectionName grpc_collection_name;
//        grpc_collection_name.set_collection_name(collection_name);
//        row_count = client_ptr_->CountEntities(grpc_collection_name, status);
        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to count collection: " + std::string(ex.what()));
    }
}

Status
ClientProxy::CreatePartition(const PartitionParam& partition_param) {
    try {
//        ::milvus::grpc::PartitionParam grpc_partition_param;
//        grpc_partition_param.set_collection_name(partition_param.collection_name);
//        grpc_partition_param.set_tag(partition_param.partition_tag);
//        Status status = client_ptr_->CreatePartition(grpc_partition_param);
        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to create partition: " + std::string(ex.what()));
    }
}

Status
ClientProxy::DropPartition(const PartitionParam& partition_param) {
    try {
//        ::milvus::grpc::PartitionParam grpc_partition_param;
//        grpc_partition_param.set_collection_name(partition_param.collection_name);
//        grpc_partition_param.set_tag(partition_param.partition_tag);
//        Status status = client_ptr_->DropPartition(grpc_partition_param);
        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to drop partition: " + std::string(ex.what()));
    }
}

bool
ClientProxy::HasPartition(const std::string& collection_name, const std::string& partition_tag) const {
    try {
        Status status = Status::OK();
//        ::milvus::grpc::PartitionParam grpc_partition_param;
//        grpc_partition_param.set_collection_name(collection_name);
//        grpc_partition_param.set_tag(partition_tag);
        return true;
    } catch (std::exception& ex) {
        return false;
    }
}

Status
ClientProxy::ListPartitions(const std::string& collection_name, PartitionTagList& partition_tag_array) const {
    try {
//        ::milvus::grpc::CollectionName grpc_collection_name;
//        grpc_collection_name.set_collection_name(collection_name);
//        ::milvus::grpc::PartitionList grpc_partition_list;
//        Status status = client_ptr_->ListPartitions(grpc_collection_name, grpc_partition_list);
//        partition_tag_array.resize(grpc_partition_list.partition_tag_array_size());
//        for (uint64_t i = 0; i < grpc_partition_list.partition_tag_array_size(); ++i) {
//            partition_tag_array[i] = grpc_partition_list.partition_tag_array(i);
//        }
        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to show partitions: " + std::string(ex.what()));
    }
}

Status
ClientProxy::CreateIndex(const IndexParam& index_param) {
    try {
        ::milvus::grpc::IndexParam grpc_index_param;
//        grpc_index_param.set_collection_name(index_param.collection_name);
//        grpc_index_param.set_field_name(index_param.field_name);
//        JSON json_param = JSON::parse(index_param.index_params);
//        for (auto& item : json_param.items()) {
//            milvus::grpc::KeyValuePair* kv = grpc_index_param.add_extra_params();
//            kv->set_key(item.key());
//            if (item.value().is_object()) {
//                kv->set_value(item.value().dump());
//            } else {
//                kv->set_value(item.value());
//            }
//        }
        return client_ptr_->CreateIndex(grpc_index_param);
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to build index: " + std::string(ex.what()));
    }
}

Status
ClientProxy::DropIndex(const std::string& collection_name, const std::string& field_name,
                       const std::string& index_name) const {
    try {
//        ::milvus::grpc::IndexParam grpc_index_param;
//        grpc_index_param.set_collection_name(collection_name);
//        grpc_index_param.set_field_name(field_name);
//        grpc_index_param.set_index_name(index_name);
//        Status status = client_ptr_->DropIndex(grpc_index_param);
        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to drop index: " + std::string(ex.what()));
    }
}

Status
ClientProxy::Insert(const std::string& collection_name, const std::string& partition_tag, const FieldValue& field_value,
                    std::vector<int64_t>& id_array) {
    Status status = Status::OK();
    try {
        ::milvus::grpc::InsertParam insert_param;
        insert_param.set_collection_name(collection_name);
        insert_param.set_partition_tag(partition_tag);

        CopyFieldValue(field_value, insert_param);

        // Single thread
        ::milvus::grpc::EntityIds entity_ids;
        if (!id_array.empty()) {
            /* set user's ids */
            auto row_ids = insert_param.mutable_entity_id_array();
            row_ids->Resize(static_cast<int>(id_array.size()), -1);
            memcpy(row_ids->mutable_data(), id_array.data(), id_array.size() * sizeof(int64_t));
            status = client_ptr_->Insert(insert_param, entity_ids);
        } else {
            status = client_ptr_->Insert(insert_param, entity_ids);
            /* return Milvus generated ids back to user */
            id_array.insert(id_array.end(), entity_ids.entity_id_array().begin(), entity_ids.entity_id_array().end());
        }
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to add entities: " + std::string(ex.what()));
    }

    return status;
}

Status
ClientProxy::GetEntityByID(const std::string& collection_name, const std::vector<int64_t>& id_array,
                           std::string& entities) {
    try {
        ::milvus::grpc::EntityIdentity entity_identity;
        entity_identity.set_collection_name(collection_name);
        for (auto id : id_array) {
            entity_identity.add_id_array(id);
        }
        ::milvus::grpc::Entities grpc_entities;

        Status status = client_ptr_->GetEntityByID(entity_identity, grpc_entities);
        if (!status.ok()) {
            return status;
        }

        Mapping schema;
        GetCollectionInfo(collection_name,schema);

        JSON json_entities;
        CopyEntityToJson(grpc_entities, json_entities, schema);
        entities = json_entities.dump();
        return status;
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to get entity by id: " + std::string(ex.what()));
    }
}

Status
ClientProxy::DeleteEntityByID(const std::string& collection_name, const std::vector<int64_t>& id_array) {
    try {
        ::milvus::grpc::DeleteByIDParam delete_by_id_param;
        delete_by_id_param.set_collection_name(collection_name);
        for (auto id : id_array) {
            delete_by_id_param.add_id_array(id);
        }

        return client_ptr_->DeleteEntityByID(delete_by_id_param);
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to delete entity id: " + std::string(ex.what()));
    }
}

Status
ClientProxy::Search(const std::string& collection_name, const std::vector<std::string>& partition_list,
                    const std::string& dsl, const VectorParam& vector_param, TopKQueryResult& query_result) {
    try {
//        ::milvus::grpc::SearchParam search_param;
//        search_param.set_collection_name(collection_name);
//        for (auto partition : partition_list) {
//            auto value = search_param.add_partition_tag_array();
//            *value = partition;
//        }
//        search_param.set_dsl(dsl);
//        auto grpc_vector_param = search_param.add_vector_param();
//        grpc_vector_param->set_json(vector_param.json_param);
//        auto grpc_vector_record = grpc_vector_param->mutable_row_record();
//        for (auto& vector_data : vector_param.vector_records) {
//            auto row_record = grpc_vector_record->add_records();
//            CopyRowRecord(row_record, vector_data);
//        }
//
//        ::milvus::grpc::QueryResult grpc_result;
//        Status status = client_ptr_->Search(search_param, grpc_result);
//        ConstructTopkQueryResult(grpc_result, query_result);
        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to search entities: " + std::string(ex.what()));
    }
}

Status
ClientProxy::ListIDInSegment(const std::string& collection_name, const std::string& segment_name,
                             std::vector<int64_t>& id_array) {
    try {
//        ::milvus::grpc::GetEntityIDsParam param;
//        param.set_collection_name(collection_name);
//        param.set_segment_name(segment_name);
//
//        ::milvus::grpc::EntityIds entity_ids;
//        Status status = client_ptr_->ListIDInSegment(param, entity_ids);
//        if (!status.ok()) {
//            return status;
//        }
//        id_array.insert(id_array.end(), entity_ids.entity_id_array().begin(), entity_ids.entity_id_array().end());
        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to get ids from segment: " + std::string(ex.what()));
    }
}

Status
ClientProxy::LoadCollection(const std::string& collection_name) const {
    try {
//        ::milvus::grpc::CollectionName grpc_collection_name;
//        grpc_collection_name.set_collection_name(collection_name);
//        Status status = client_ptr_->LoadCollection(grpc_collection_name);
        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to preload collection: " + std::string(ex.what()));
    }
}

Status
ClientProxy::Flush(const std::vector<std::string>& collection_name_array) {
    try {
//        if (collection_name_array.empty()) {
//            return client_ptr_->Flush("");
//        } else {
//            for (auto& collection_name : collection_name_array) {
//                client_ptr_->Flush(collection_name);
//            }
//        }
        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to flush collection");
    }
}

Status
ClientProxy::Compact(const std::string& collection_name) {
    try {
//        ::milvus::grpc::CollectionName grpc_collection_name;
//        grpc_collection_name.set_collection_name(collection_name);
//        Status status = client_ptr_->Compact(grpc_collection_name);
        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to compact collection: " + std::string(ex.what()));
    }
}

/*******************************New Interface**********************************/

void
WriteQueryToProto(::milvus::grpc::GeneralQuery* general_query, BooleanQueryPtr boolean_query) {
//    if (!boolean_query->GetBooleanQueries().empty()) {
//        for (auto query : boolean_query->GetBooleanQueries()) {
//            auto grpc_boolean_query = general_query->mutable_boolean_query();
//            grpc_boolean_query->set_occur((::milvus::grpc::Occur)query->GetOccur());
//
//            for (auto leaf_query : query->GetLeafQueries()) {
//                auto grpc_query = grpc_boolean_query->add_general_query();
//                if (leaf_query->term_query_ptr != nullptr) {
//                    auto term_query = grpc_query->mutable_term_query();
//                    term_query->set_field_name(leaf_query->term_query_ptr->field_name);
//                    term_query->set_boost(leaf_query->query_boost);
//                    if (leaf_query->term_query_ptr->int_value.size() > 0) {
//                        auto mutable_int_value = term_query->mutable_int_value();
//                        auto size = leaf_query->term_query_ptr->int_value.size();
//                        mutable_int_value->Resize(size, 0);
//                        memcpy(mutable_int_value->mutable_data(), leaf_query->term_query_ptr->int_value.data(),
//                               size * sizeof(int64_t));
//                    } else if (leaf_query->term_query_ptr->double_value.size() > 0) {
//                        auto mutable_double_value = term_query->mutable_double_value();
//                        auto size = leaf_query->term_query_ptr->double_value.size();
//                        mutable_double_value->Resize(size, 0);
//                        memcpy(mutable_double_value->mutable_data(), leaf_query->term_query_ptr->double_value.data(),
//                               size * sizeof(double));
//                    }
//                }
//                if (leaf_query->range_query_ptr != nullptr) {
//                    auto range_query = grpc_query->mutable_range_query();
//                    range_query->set_boost(leaf_query->query_boost);
//                    range_query->set_field_name(leaf_query->range_query_ptr->field_name);
//                    for (auto com_expr : leaf_query->range_query_ptr->compare_expr) {
//                        auto grpc_com_expr = range_query->add_operand();
//                        grpc_com_expr->set_operand(com_expr.operand);
//                        grpc_com_expr->set_operator_((milvus::grpc::CompareOperator)com_expr.compare_operator);
//                    }
//                }
//                if (leaf_query->vector_query_ptr != nullptr) {
//                    auto vector_query = grpc_query->mutable_vector_query();
//                    vector_query->set_field_name(leaf_query->vector_query_ptr->field_name);
//                    vector_query->set_query_boost(leaf_query->query_boost);
//                    vector_query->set_topk(leaf_query->vector_query_ptr->topk);
//                    for (auto record : leaf_query->vector_query_ptr->query_vector) {
//                        ::milvus::grpc::VectorRowRecord* row_record = vector_query->add_records();
//                        CopyRowRecord(row_record, record);
//                    }
//                    auto extra_param = vector_query->add_extra_params();
//                    extra_param->set_key(EXTRA_PARAM_KEY);
//                    extra_param->set_value(leaf_query->vector_query_ptr->extra_params);
//                }
//            }
//
//            if (!query->GetBooleanQueries().empty()) {
//                ::milvus::grpc::GeneralQuery* next_query = grpc_boolean_query->add_general_query();
//                WriteQueryToProto(next_query, query);
//            }
//        }
//    }
}

Status
ClientProxy::SearchPB(const std::string& collection_name, const std::vector<std::string>& partition_list,
                      BooleanQueryPtr& boolean_query, const std::string& extra_params,
                      TopKQueryResult& topk_query_result) {
    try {
        // convert boolean_query to proto
//        ::milvus::grpc::SearchParamPB search_param;
//        search_param.set_collection_name(collection_name);
//        for (auto partition : partition_list) {
//            auto value = search_param.add_partition_tag_array();
//            *value = partition;
//        }
//        if (extra_params.size() > 0) {
//            auto extra_param = search_param.add_extra_params();
//            extra_param->set_key("params");
//            extra_param->set_value(extra_params);
//        }
//        WriteQueryToProto(search_param.mutable_general_query(), boolean_query);
//
//        // step 2: search vectors
//        ::milvus::grpc::QueryResult result;
//        Status status = client_ptr_->SearchPB(search_param, result);
//
//        // step 3: convert result array
//        ConstructTopkQueryResult(result, topk_query_result);
        return Status::OK();
    } catch (std::exception& ex) {
        return Status(StatusCode::UnknownError, "Failed to search entities: " + std::string(ex.what()));
    }
}

}  // namespace milvus
