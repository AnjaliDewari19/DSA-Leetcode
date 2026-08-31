class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int firstCriticalIndex = -1;
        int prevCriticalIndex = -1;
        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next != nullptr) {
            ListNode* nextNode = curr->next;
            
            // Check if current node is a critical point
            if ((curr->val > prev->val && curr->val > nextNode->val) ||
                (curr->val < prev->val && curr->val < nextNode->val)) {
                
                if (firstCriticalIndex == -1) {
                    firstCriticalIndex = index;
                } else {
                    minDistance = min(minDistance, index - prevCriticalIndex);
                }
                prevCriticalIndex = index;
            }

            prev = curr;
            curr = nextNode;
            index++;
        }

        // Return result if at least two critical points were found
        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        int maxDistance = prevCriticalIndex - firstCriticalIndex;
        return {minDistance, maxDistance};
    }
};