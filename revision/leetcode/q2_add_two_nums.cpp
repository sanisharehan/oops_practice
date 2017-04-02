/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//link: https://leetcode.com/problems/add-two-numbers/

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val_1 = 0, val_2 = 0;
        ListNode *next1 = l1->next, *next2 = l2->next, *e_next;
        ListNode *final_result;
        
        val_1 = l1->val;
        val_2 = l2->val;
        
        int add = val_1 + val_2;
        // Get the next pointers
        int mod, divi;
        mod = add % 10;
        divi = add/10;
        
        ListNode *res = new ListNode(mod);
        final_result = res;
        
        while (next1 != NULL && next2 != NULL) {
            val_1 = next1->val;
            val_2 = next2->val;
            
            add = val_1 + val_2 + divi;
            mod = add % 10;
            divi = add/10;
            
            ListNode *temp = new ListNode(mod);
            res->next = temp;
            res = temp;
            
            next1 = next1->next;
            next2 = next2->next;
        }
        
        if (next2 != NULL) {
            e_next = next2;
        } else {
            e_next = next1;
        }
        
        while (e_next != NULL) {
            add = e_next->val + divi;
            mod = add % 10;
            divi = add/10;
            
            ListNode *temp = new ListNode(mod);
            res->next = temp;
            res = temp;
            
            e_next = e_next->next;
        }
        /*
        while (next2 != NULL) {
            add = next2->val + divi;
            mod = add % 10;
            divi = add/10;
            
            ListNode *temp = new ListNode(mod);
            res->next = temp;
            res = temp;
            
            next2 = next2->next;
        }*/
        if (divi != 0) {
            ListNode *temp = new ListNode(divi);
            res->next = temp;
            res = temp;
        }
        return final_result;
    }
};

//********************************************************************


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num_stack;
        int count = 0;
        
        int val_1 = 0, val_2 = 0;
        ListNode *next1 = l1->next, *next2 = l2->next;
        
        val_1 = l1->val;
        val_2 = l2->val;
        count++;
        
        num_stack.push_back(val_1 + val_2);
        
        // Get the next pointers
        while (next1 != NULL && next2 != NULL) {
            val_1 = next1->val;
            val_2 = next2->val;
            
            num_stack.push_back(val_1 + val_2);
            count++;
            
            next1 = next1->next;
            next2 = next2->next;
        }
        
        while (next1 != NULL) {
            val_1 = next1->val;
            num_stack.push_back(val_1);
            count++;
            next1 = next1->next;
        }
        while (next2 != NULL) {
            val_2 = next2->val;
            num_stack.push_back(val_2);
            count++;
            next2 = next2->next;
        }
        
        cout << "Total values: " << count << endl;
        int count2 = count;
        unsigned int res = 0.;
        unsigned int  final_val = 0.;
        //cout << "power " << (unsigned int) pow(10 , (count2-1)) << endl;
        while (count2 > 0) {
            res = num_stack.back();
            cout << "Before res " << res << endl;
            unsigned int a = pow(10 , (count2-1));
            cout << "a: " << a << endl;
            res = res * a;
            cout << "res: " << res << endl;
            final_val = final_val + res;
            num_stack.pop_back();
            count2--;
            cout << "Sum: " << final_val << endl;
        }
        
        // Convert result to reverse linked list.
        cout << "Final sum: " << (unsigned int ) final_val ;
        int divi = final_val/10;
        int mod = (unsigned int) final_val % 10;
        ListNode *sol = new ListNode(mod);
        ListNode *sol_final;
        //sol->val = mod;
        //sol->next = NULL;
        sol_final = sol;
        while (divi != 0) {
            mod = divi % 10;
            ListNode *l = new ListNode(mod);
            //l->val = mod;
            //l->next = NULL;
            sol->next = l;
            sol = l;
            //mod = divi % 10;
            divi = divi/10;
        }
        return sol_final;
    }
};