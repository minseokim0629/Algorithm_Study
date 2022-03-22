def solution(phone_book):
    answer = ''
    hash_map = {}
    
    for i in phone_book:
        hash_map[i] = 1
    
    for phone_number in phone_book:
        tmp = ''
        for number in phone_number:
            tmp += number
            if(tmp in hash_map and tmp != phone_number):
                return False
    
    return True
