// Copyright 2011 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "syzygy/pdb/pdb_stream.h"

namespace {

const size_t kInvalidLength = 0xFFFFFFFF;

}  // namespace

namespace pdb {

PdbStream::PdbStream(size_t length)
    : length_(length == kInvalidLength ? 0 : length), pos_(0) {
}

PdbStream::~PdbStream() {
}

bool PdbStream::Seek(size_t pos) {
  if (pos > length_)
    return false;

  pos_ = pos;
  return true;
}

}  // namespace pdb
