#
# Platform: Programmers
# Title: 주차 요금 계산
#

import heapq
import math

def solution(fees, records):
    answer = []
    maxCarNumber = 9999;
    maxTimestamp = 23 * 60 + 59;
    timestamps = [[] for i in range(maxCarNumber + 1)]
    cars = []
    
    #
    # Group timestamps by car.
    #
    for record in records:
        time, car, status = record.split(" ")
        car = int(car)
        time = int(time[0:2]) * 60 + int(time[3:5])
        
        if (0 == len(timestamps[car])):
            cars.append(car)
        
        timestamps[car].append(time)
    
    #
    # Sort cars from smallest to largest in number.
    #
    cars.sort()
    
    #
    # Get parking fees of cars.
    #
    for car in cars:
        timestampCnt = len(timestamps[car]);
        
        if(0 != timestampCnt % 2):
            timestamps[car].append(maxTimestamp)
            
        totalTime = -fees[0];
        for i in range(0, timestampCnt, 2):
            totalTime += timestamps[car][i + 1] - timestamps[car][i]
            
        answer.append(fees[1] + (0 if (0 > totalTime) else (math.ceil(totalTime / fees[2]) * fees[3])))
    
    return answer