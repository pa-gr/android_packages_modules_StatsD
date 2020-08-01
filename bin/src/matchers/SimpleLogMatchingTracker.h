/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SIMPLE_LOG_MATCHING_TRACKER_H
#define SIMPLE_LOG_MATCHING_TRACKER_H

#include <unordered_map>
#include <vector>
#include "LogMatchingTracker.h"
#include "packages/modules/StatsD/bin/src/statsd_config.pb.h"
#include "packages/UidMap.h"

namespace android {
namespace os {
namespace statsd {

class SimpleLogMatchingTracker : public virtual LogMatchingTracker {
public:
    SimpleLogMatchingTracker(const int64_t& id, const int index, const uint64_t protoHash,
                             const SimpleAtomMatcher& matcher, const sp<UidMap>& uidMap);

    ~SimpleLogMatchingTracker();

    bool init(const std::vector<AtomMatcher>& allLogMatchers,
              const std::vector<sp<LogMatchingTracker>>& allTrackers,
              const std::unordered_map<int64_t, int>& matcherMap,
              std::vector<bool>& stack) override;

    void onLogEvent(const LogEvent& event,
                    const std::vector<sp<LogMatchingTracker>>& allTrackers,
                    std::vector<MatchingState>& matcherResults) override;

private:
    const SimpleAtomMatcher mMatcher;
    const sp<UidMap> mUidMap;
};

}  // namespace statsd
}  // namespace os
}  // namespace android
#endif  // SIMPLE_LOG_MATCHING_TRACKER_H
