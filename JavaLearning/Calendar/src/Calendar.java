import java.util.Scanner;

public class Calendar {

    public static void main(String args[]){
        System.out.println("\033c");
        Scanner receiver = new Scanner(System.in);
        Calendar c = new Calendar();
        System.out.println("This is a calendar made by MTDoven. (2023,1,23)");
        while (true) {
            c.pressEnterToContinue();
            System.out.print("\033c");
            ////////////////////////////// 0. Press any key to continue ///////////////////////////////////
            System.out.print("Choose a mode the calendar works.\n"+
                    "    1. Query the annual calendar\n    2. Check the day of the week\n"+
                    "Please enter 1/2 (or 0 to exit) to choose the mode: ");
            int mode = receiver.nextInt();
            ////////////////////////////// 1. Query the annual calendar ///////////////////////////////////
            if (mode==1){
                System.out.print("Please enter the year you want to query: ");
                int year = receiver.nextInt();
                int week_of_day_the_first_day = c.getDayOfWeek(year, 1, 1);
                c.printCalendars(week_of_day_the_first_day, c.isLeapYear(year));
            } // 1. Query the annual calendar
            ////////////////////////////// 2. Check the day of the week ///////////////////////////////////
            else if (mode==2){
                System.out.print("Please enter the day(example: 2023-2-28) you want to query: ");
                String[] day = receiver.next().split("-|/");
                int day_of_week = c.getDayOfWeek(Integer.parseInt(day[0]),
                        Integer.parseInt(day[1]),Integer.parseInt(day[2]));
                String[] weekday2words = {"Error","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
                System.out.println("\nThis day is "+weekday2words [day_of_week]);
            } else break;// 2. Check the day of the week
            ///////////////////////////////////////////////////////////////////////////////////////////////
        } // loop
        System.out.println("\033c");
        System.out.println("Thank you for using !!!");
        c.pressEnterToContinue();
    } // static main
    ///////////////////////////////////////////////////////////////////////////////////////////////


    // 2. Check the day of the week
    boolean isLeapYear(int year){
        if (year%400==0) return true;
        else if (year%100==0) return false;
        else if (year%4==0) return true;
        else return false;
    }
    int getDaysBeforeThisDayInThisYear(int year, int month, int day){
        byte leap_plus=0;
        if (isLeapYear(year)) leap_plus=1;
        // if this year is leap year, add one to leap_plus
        switch(month){
            case 1: return day;
            case 2: return 31+day;
            case 3: return 59+day+leap_plus;
            case 4: return 90+day+leap_plus;
            case 5: return 120+day+leap_plus;
            case 6: return 151+day+leap_plus;
            case 7: return 181+day+leap_plus;
            case 8: return 212+day+leap_plus;
            case 9: return 243+day+leap_plus;
            case 10: return 273+day+leap_plus;
            case 11: return 304+day+leap_plus;
            case 12: return 334+day+leap_plus;
        } // switch month
        return -1;
    }
    int getDaysBeforeThisDayInPastYear(int year){
        int days = 0;
        for (int i=1583; i<year; i++){
            if (isLeapYear(i)) days+=366;
            else days+=365;
        } // days in past years
        return days;
    }
    int getDayOfWeek(int year, int month, int day){
        int days = getDaysBeforeThisDayInThisYear(year, month, day);
        if(days==-1) return 0;
        days += getDaysBeforeThisDayInPastYear(year);
        return (days+4)%7+1;
    }

    // 1. Query the annual calendar
    int month=1;
    int month2Days(int month, boolean is_leap_year){
        switch(month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
            case 4: case 6: case 9: case 11: return 30;
            case 2: {if (is_leap_year) return 29; else return 28; }
        } // month2Days
        return 0;
    }
    void printOneLine(int first_number, int pos_next_line, int month){
        for(int i=0; i<7; i++){
            System.out.print((first_number+i)+"\t");
            if (pos_next_line-1==i) {
                System.out.println();
                System.out.println("\n\t\t "+month2Words(month+1)+":\nMon.\tTue.\tWed.\tTur.\tFri.\tSat.\tSun.");
                for(int j=0; j<pos_next_line; j++)
                    System.out.print("\t");
                for(int j=1; j<=7-pos_next_line; j++)
                    System.out.print(j+"\t");
                break;
            } // If there is a \n
        } // print loop
        System.out.println();
    }
    void printCalendars(int first_day_of_week, boolean is_leap_year){
        int day=0;
        int pos_next_line = 0;
        int month = 1;
        System.out.println("\n\t\t January:\nMon.\tTue.\tWed.\tTur.\tFri.\tSat.\tSun.");
        for(int i=1; i<first_day_of_week; i++)
            System.out.print("\t");
        for(day=1; day<=8-first_day_of_week; day++)
            System.out.print(day+"\t");
        System.out.println();
        // day=5
        while(month<=12){
            printOneLine(day, pos_next_line, month);
            day += 7;
            if (day+6 == month2Days(month, is_leap_year)){
                if (month!=12){
                    printOneLine(day, 7, month);
                    day=1;
                } else {
                    printOneLine(day, 0, month);
                    break;
                }
            }
            else if (day+7 <= month2Days(month, is_leap_year)){
                pos_next_line = 0;
            }
            else {
                if (month!=12){
                    printOneLine(day, 1-day+month2Days(month, is_leap_year), month);
                    day = 8-(1-day+month2Days(month, is_leap_year));
                } else {
                    for(; day<=31; day++)
                        System.out.print(day+"\t");
                    break;
                }
                month++;
            }
        }
        System.out.print("\n\n");
    }

    // 0. Other tools
    void pressEnterToContinue() {
        System.out.println("\nPress Enter key to continue...");
        try {System.in.read(); }
        catch(Exception e) {}
    }
    String month2Words(int month){
        String month_name;
        switch(month){
            case 1: {month_name="January"; break;}
            case 2: {month_name="February"; break;}
            case 3: {month_name="March"; break;}
            case 4: {month_name="April"; break;}
            case 5: {month_name="May"; break;}
            case 6: {month_name="June"; break;}
            case 7: {month_name="July"; break;}
            case 8: {month_name="August"; break;}
            case 9: {month_name="September"; break;}
            case 10: {month_name="October"; break;}
            case 11: {month_name="November"; break;}
            case 12: {month_name="December"; break;}
            default: month_name="Error";
        }
        return month_name;
    }
}
