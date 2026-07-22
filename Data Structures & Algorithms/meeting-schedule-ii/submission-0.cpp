/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
    struct IntervalGreaterThanComparatorWithEnd {
        bool operator()(const Interval& a, const Interval& b) {
            return a.end > b.end;
        }
    };
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start || a.start == b.start && a.end < b.end;
        });

        priority_queue<Interval, vector<Interval>, IntervalGreaterThanComparatorWithEnd> ongoingMeetings;

        int minimumRooms = 0;
        for (int i=0 ; i<intervals.size() ; ++i) {
            while (!ongoingMeetings.empty() && ongoingMeetings.top().end <= intervals[i].start) {
                ongoingMeetings.pop();
            }
            ongoingMeetings.push(intervals[i]);
            minimumRooms = max(minimumRooms, static_cast<int>(ongoingMeetings.size()));
        }

        return minimumRooms;
    }
};
