class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {

        sort(events.begin(), events.end(), [] (auto e1, auto e2) { 
            if(stoi(e1[1]) == stoi(e2[1]))
            return e1[0][0] > e2[0][0];   //if same timeStamp then put offline event first i.e. return true if e1[0][0]=='o' (offline)
            
            return stoi(e1[1]) < stoi(e2[1]);   // else put less timeStamp first
             
        }); 
        
        //for every event go through all users and update their mentions TC= events_Size*numberOfUsers
        vector<int> offlineTime(numberOfUsers, 0);  // user -> end of offline time i.e. time upto which i'th user is offline
        vector<int> mentions(numberOfUsers, 0);   // store number of times a user is mentioned          
        
        for(int i = 0; i < events.size(); i++)
        {  
            string eventName = events[i][0];
            int timeStamp = stoi(events[i][1]);
            string mentionedIds = events[i][2];
            
            if(eventName == "MESSAGE")
            {   
                if(mentionedIds == "ALL")  //mention all users
                {      
                    for(int i = 0; i < numberOfUsers; i++)
                        mentions[i]++;
                }
                else if(mentionedIds == "HERE")  //mention all online users
                {   
                    for(int i = 0; i < numberOfUsers; i++)
                    {
                       //if user is online(i.e. not offline) then count its mention
                       // at time 'timeStamp + 60' id will be online so include this time as well
                        if(offlineTime[i] <= timeStamp)   
                            mentions[i]++;
                    }
                }
                else
                {   
                    //mention all given ids
                    for(int i = 0; i < mentionedIds.size(); i++)
                    {
                        if(mentionedIds[i] == 'd')
                        {
                            i++;  // index next to 'd' contains id number
                            string id = "";  // id can be of >1 digits so get all the digits
                            while(i < mentionedIds.size() && mentionedIds[i] != ' ')
                            {
                                id += mentionedIds[i];
                                i++;
                            }

                            mentions[stoi(id)]++;
                        }
                    }
                }
            }
            
            //if its "OFFLINE" event
            else  
            {  
                int id = stoi(mentionedIds); // get user no. to be set offline

                //set the time upto which this user will be offline
                offlineTime[id] = timeStamp + 60; // at time 'timeStamp + 60' id will be online
            }
        }
        return mentions;
    }   

};