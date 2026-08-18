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

struct Marker {
    int timestamp;
    bool isIntervalStart;

    bool operator()(Marker& a, Marker& b) {
        if (a.timestamp != b.timestamp) {
            return a.timestamp < b.timestamp;
        } else {
            return a.isIntervalStart < b.isIntervalStart;
        }
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<Marker> events(intervals.size()*2, {0 , false});
        for (int i=0 ; i<intervals.size() ; ++i) {
            events[i*2] = {intervals[i].start, true};
            events[i*2+1] = {intervals[i].end, false};
        }

        sort(events.begin(), events.end(), Marker());

        int minimumRooms = 0;
        int currentRooms = 0;
        for (int i=0 ; i<events.size() ; ++i) {
            if (events[i].isIntervalStart) {
                currentRooms++;
            } else {
                currentRooms--;
            }

            minimumRooms = max(minimumRooms, currentRooms);
        }

        return minimumRooms;
    }
};
