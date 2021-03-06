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

#ifndef MOZC_DATA_MANAGER_CHROMEOS_CHROMEOS_DATA_MANAGER_H_
#define MOZC_DATA_MANAGER_CHROMEOS_CHROMEOS_DATA_MANAGER_H_

#include "base/port.h"
#include "data_manager/chromeos/chromeos_user_pos_manager.h"
#include "data_manager/data_manager.h"

namespace mozc {
namespace chromeos {

class ChromeOsDataManager : public ChromeOsUserPosManager {
 public:
  ChromeOsDataManager();
  ~ChromeOsDataManager() override;

  const uint8 *GetPosGroupData() const override;
  void GetConnectorData(const char **data, size_t *size) const override;
  void GetSegmenterData(size_t *l_num_elements, size_t *r_num_elements,
                        const uint16 **l_table, const uint16 **r_table,
                        size_t *bitarray_num_bytes, const char **bitarray_data,
                        const uint16 **boundary_data) const override;
  void GetSystemDictionaryData(const char **data, int *size) const override;
  void GetSuffixDictionaryData(StringPiece *key_array, StringPiece *value_array,
                               const uint32 **token_array) const override;
  void GetReadingCorrectionData(
      StringPiece *value_array_data, StringPiece *error_array_data,
      StringPiece *correction_array_data) const override;
  void GetCollocationData(const char **array, size_t *size) const override;
  void GetCollocationSuppressionData(const char **array,
                                     size_t *size) const override;
  void GetSuggestionFilterData(const char **data, size_t *size) const override;
  void GetSymbolRewriterData(StringPiece *token_array_data,
                             StringPiece *string_array_data) const override;
#ifndef NO_USAGE_REWRITER
  void GetUsageRewriterData(
      StringPiece *base_conjugation_suffix_data,
      StringPiece *conjugation_suffix_data,
      StringPiece *conjugation_suffix_index_data,
      StringPiece *usage_items_data,
      StringPiece *string_array_data) const override;
#endif  // NO_USAGE_REWRITER
  void GetCounterSuffixSortedArray(const char **array,
                                   size_t *size) const override;

 private:
  DataManager manager_;
  DISALLOW_COPY_AND_ASSIGN(ChromeOsDataManager);
};

}  // namespace chromeos
}  // namespace mozc

#endif  // MOZC_DATA_MANAGER_CHROMEOS_CHROMEOS_DATA_MANAGER_H_
