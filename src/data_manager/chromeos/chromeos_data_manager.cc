// Copyright 2010-2016, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "data_manager/chromeos/chromeos_data_manager.h"
#include "data_manager/chromeos/chromeos_data_manager_factory.h"

#include "base/embedded_file.h"
#include "base/logging.h"
#include "base/port.h"
#include "base/singleton.h"
#include "converter/boundary_struct.h"
#include "dictionary/pos_matcher.h"

namespace mozc {
namespace chromeos {

const DataManagerInterface *CreateDataManager() {
  return new ChromeOsDataManager();
}

void DeleteDataManager(const DataManagerInterface *data_manager) {
  delete data_manager;
}

namespace {

// kCrosMozcDataSet is defined.
#include "data_manager/chromeos/cros_mozc_data.h"

#ifndef MOZC_DATASET_MAGIC_NUMBER
#error "MOZC_DATASET_MAGIC_NUMBER is not defined by build system"
#endif  // MOZC_DATASET_MAGIC_NUMBER

const char kMagicNumber[] = MOZC_DATASET_MAGIC_NUMBER;

}  // namespace

ChromeOsDataManager::ChromeOsDataManager() {
  const StringPiece magic(kMagicNumber, arraysize(kMagicNumber) - 1);
  CHECK(manager_.InitFromArray(LoadEmbeddedFile(kCrosMozcDataSet), magic))
      << "Embedded cros_mozc_data.h is broken";
}

ChromeOsDataManager::~ChromeOsDataManager() = default;

const uint8 *ChromeOsDataManager::GetPosGroupData() const {
  return manager_.GetPosGroupData();
}

void ChromeOsDataManager::GetConnectorData(const char **data,
                                           size_t *size) const {
  manager_.GetConnectorData(data, size);
}

void ChromeOsDataManager::GetSystemDictionaryData(
    const char **data, int *size) const {
  manager_.GetSystemDictionaryData(data, size);
}

void ChromeOsDataManager::GetSegmenterData(
    size_t *l_num_elements, size_t *r_num_elements,
    const uint16 **l_table, const uint16 **r_table,
    size_t *bitarray_num_bytes, const char **bitarray_data,
    const uint16 **boundary_data) const {
  manager_.GetSegmenterData(l_num_elements, r_num_elements,
                            l_table, r_table, bitarray_num_bytes,
                            bitarray_data, boundary_data);
}

void ChromeOsDataManager::GetSuffixDictionaryData(
    StringPiece *key_array, StringPiece *value_array,
    const uint32 **token_array) const {
  manager_.GetSuffixDictionaryData(key_array, value_array, token_array);
}

void ChromeOsDataManager::GetReadingCorrectionData(
    StringPiece *value_array_data, StringPiece *error_array_data,
    StringPiece *correction_array_data) const {
  manager_.GetReadingCorrectionData(value_array_data, error_array_data,
                                    correction_array_data);
}

void ChromeOsDataManager::GetCollocationData(const char **array,
                                             size_t *size) const {
  manager_.GetCollocationData(array, size);
}

void ChromeOsDataManager::GetCollocationSuppressionData(const char **array,
                                                        size_t *size) const {
  manager_.GetCollocationSuppressionData(array, size);
}

void ChromeOsDataManager::GetSuggestionFilterData(const char **data,
                                                  size_t *size) const {
  manager_.GetSuggestionFilterData(data, size);
}

void ChromeOsDataManager::GetSymbolRewriterData(
    StringPiece *token_array_data, StringPiece *string_array_data) const {
  manager_.GetSymbolRewriterData(token_array_data, string_array_data);
}

#ifndef NO_USAGE_REWRITER
void ChromeOsDataManager::GetUsageRewriterData(
    StringPiece *base_conjugation_suffix_data,
    StringPiece *conjugation_suffix_data,
    StringPiece *conjugation_suffix_index_data,
    StringPiece *usage_items_data,
    StringPiece *string_array_data) const {
  manager_.GetUsageRewriterData(base_conjugation_suffix_data,
                                conjugation_suffix_data,
                                conjugation_suffix_index_data,
                                usage_items_data,
                                string_array_data);
}
#endif  // NO_USAGE_REWRITER

void ChromeOsDataManager::GetCounterSuffixSortedArray(
    const char **array, size_t *size) const {
  manager_.GetCounterSuffixSortedArray(array, size);
}

}  // namespace chromeos
}  // namespace mozc
