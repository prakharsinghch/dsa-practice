class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string suff) {
        return s(finish, limit, suff) - s(start - 1, limit, suff);
    }

private:
    long long s(long long end, int limit, string& suff) {
        string number = to_string(end);
        int l = number.size() - suff.size();
        if(l < 0) return 0;

        string suff_number = number.substr(l, suff.size()); // get actual suffix in end number
        bool cmp = suff_number >= suff; // check if suffix in number is valid

        return h(number, limit, 0, 1, l, cmp);
    }

    long long h(string& number, int& limit, int i, int set, int& end, bool& cmp) {
        if(i == end) {
            return set ? cmp : 1; // check validity at suffix attachment point
        }

        int d = number[i] - '0';
        long long count = 0;

        if(set) {
            for(int j = 0; j <= min(d, limit); j++) {
                if(j == d) count += h(number, limit, i + 1, 1, end, cmp); // stay tight
                else count += h(number, limit, i + 1, 0, end, cmp); // become loose
            }
        } else {
            count += (limit + 1) * h(number, limit, i + 1, 0, end, cmp); // free to choose
        }

        return count;
    }
};