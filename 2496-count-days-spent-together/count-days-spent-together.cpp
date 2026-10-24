class Solution {
public:
    int getDayOfYear(string date){
        vector<int> day_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3,2));

        int day_year = day;
        for(int i=0 ; i<month-1 ; ++i){
            day_year += day_month[i];
        }

        return day_year;
    }
    
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceA = getDayOfYear(arriveAlice), aliceL = getDayOfYear(leaveAlice);
        int bobA = getDayOfYear(arriveBob), bobL = getDayOfYear(leaveBob);

        int start = max(aliceA, bobA);
        int end = min(aliceL, bobL);

        if(start <= end){
            return end-start+1;
        }

        return 0;
    }
};