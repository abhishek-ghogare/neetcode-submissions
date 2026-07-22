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
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, bool>> events(intervals.size()*2, {0 , false});
        for (int i=0 ; i<intervals.size() ; ++i) {
            events[i*2] = {intervals[i].start, true};
            events[i*2+1] = {intervals[i].end, false};
        }

        sort(events.begin(), events.end());

        int minimumRooms = 0;
        int currentRooms = 0;
        for (int i=0 ; i<events.size() ; ++i) {
            if (events[i].second) {
                currentRooms++;
            } else {
                currentRooms--;
            }

            minimumRooms = max(minimumRooms, currentRooms);
        }

        return minimumRooms;
    }
};
