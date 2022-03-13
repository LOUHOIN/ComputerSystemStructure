import datetime


def DaysPass(date1, date2):
    d1 = datetime.datetime.strptime(date1, '%Y%m%d')
    d2 = datetime.datetime.strptime(date2, '%Y%m%d')
    d3 = d2 - d1
    # print(d3.days)
    return d3.days


def BookPrice(days):
    if days > 180:
        money = 250
        print("You are late, please pay $%.1f!" % (money))
    elif (days > 30) and (days <= 60):
        money = (days - 30) * 0.5
        print("You are late, please pay $%.1f!" % (money))
    elif (days > 60) and (days <= 180):
        money = 15 + (days - 60) * 0.7
        print("You are late, please pay $%.1f!" % (money))
    else:
        print("The return is successful!")


if __name__ == '__main__':
    data1_list = ["20200228", "20151030", "20170523", "20191215", "20191215"]
    data2_list = ["20200309", "20160408", "20180615", "20200114", "20200115"]
    for i in range(0, 5):
        days = int(DaysPass(data1_list[i], data2_list[i]))
        BookPrice(days)

