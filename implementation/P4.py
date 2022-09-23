#
# Platform: Programmers
# Title: 신고 결과 받기
#

def solution(id_list, report, k):
    max_user_cnt = 1000;
    is_reported = [[False] * max_user_cnt for i in range(max_user_cnt)]
    reported_cnt = [-k] * max_user_cnt;
    answer = [0 for x in id_list]

    #
    # Create numerical id's for id's.
    #
    id_cnt = len(id_list)
    id_map = {id_list[x] : x for x in range(id_cnt)}

    #
    # Linearly shift through all reports and log reported information.
    #
    for record in report:
        reporter, reportee = map(lambda x: id_map[x], record.split(" "))
        if (not is_reported[reportee][reporter]):
            is_reported[reportee][reporter] = True
            reported_cnt[reportee] += 1

    #
    # Determine users to be blocked, and send notification mails accordingly.
    #
    for i in range(id_cnt):
        if (0 <= reported_cnt[i]):
            for j in range(id_cnt):
                if (is_reported[i][j]):
                    answer[j] += 1

    return answer