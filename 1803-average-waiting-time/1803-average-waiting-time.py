class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        twt=0
        current=0
        for arrival,service in customers:
            if current<arrival:
                current=arrival
            wt=current-arrival+service
            twt+=wt
            current+=service
        return twt/len(customers)
