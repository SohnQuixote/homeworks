package level3;

public class maingame{
public final static int nodoing = -1;
public final static int ending =0;
//엔딩 행동 1개
public final static int feed =1;
public final static int punish =2;
public final static int pet =3;
public final static int syringe =4;
//리스크 없는 공통행동 4개
public final static int feed_trash =5;
public final static int punish_harder =6;
public final static int read_story =7;
public final static int hard_training = 8;
//리스크 있는 공통행동 4개
public final static int special_doctor =9;
public final static int special_farmer =10;
public final static int special_soldier =11;
public final static int special_mentalist =12;
//직업에 따라 다른 특수행동
//인터페이스로부터 행동선택할때만 입력받음
public final static int pranc =1;
public final static int vamp = 2;
public final static int zombie =3;
//인터페이스로부터 입력받음
public final static int doctor =1;
public final static int soldier =2;
public final static int mentalist =3;
public final static int farmer = 4;
//인터페이스로 부터 입력받음
//인터페이스로 부터 처음에만 입력받음
public final static int still_ok = 0;
public final static int bad_ending_hunger_pranc =1;
public final static int bad_ending_health_pranc =2;
public final static int bad_ending_mental_pranc =3;
public final static int bad_ending_obedience_pranc =4;
public final static int bad_ending_hunger_vamp =5;
public final static int bad_ending_health_vamp =6;
public final static int bad_ending_mental_vamp =7;
public final static int bad_ending_obedience_vamp =8;
public final static int bad_ending_hunger_zombie =9;
public final static int bad_ending_health_zombie =10;
public final static int bad_ending_mental_zombie =11;
public final static int bad_ending_obedience_zombie =12;
//0이된 스탯에 따라 다른엔딩을 제공해야함 생명체 타입도 체크 가능
public final static int clear_ending_pranc =13;
public final static int clear_ending_vamp = 14;
public final static int clear_ending_zombie = 15;

public final static int bad_over_ending  =16;
//생명체 타입에 따라 다른 리턴발류
public final static int first_pranc_hunger =20;
public final static int first_pranc_health = 25;
public final static int first_pranc_mental = 40;
public final static int first_pranc_obedience = 35;
public final static int first_vamp_hunger =30;
public final static int first_vamp_health = 20;
public final static int first_vamp_mental = 30;
public final static int first_vamp_obedience  =40;
public final static int first_zombie_hunger =40;
public final static int first_zombie_health =25;
public final static int first_zombie_mental = 20;
public final static int first_zombie_obedience = 30;
//생명체에 따른 초기스탯들



public static int decrease_hunger_pranc = 4;
public static int decrease_health_pranc = 3;
public static int decrease_mental_pranc = 6;
public static int decrease_obedience_pranc = 5;
public static int decrease_hunger_vamp =4;
public static int decrease_health_vamp =2;
public static int decrease_mental_vamp =4;
public static int decrease_obedience_vamp =8;
public static int decrease_hunger_zombie = 7;
public static int decrease_health_zombie = 3;
public static int decrease_mental_zombie =2;
public static int decrease_obedience_zombie = 4;

public static float passive_rate = 4/5;

public static String event_name_1 = "경찰의 방문!!!";
public static String event_text_1 = "신고를 받은 경찰이 방문했다!!! 경찰을 죽일것인가???";
public static String event_result_yes_1 = "경찰을 죽여서 자극을 받은 생명체가 더 흉폭해졌다...";
public static String event_result_no_1 = "조용히 숨어있었더니 경찰이 알아서 사라졌다...";
public static final int event_index_1 = 0;
public static String event_name_2 = "수상한 상인의 방문!!!";
public static String event_text_2 = "수상한 상인이 싼값에 이상해보이는 물약을 판다!!! 구매할것인가???";
public static String event_result_yes_2 = "수상한 물약을 구매하고 열어보니 폭발을 일으켰다...";
public static String event_result_no_2 = "수상한 상인이 아쉬운듯 인상을 쓰며 사라졌다...";
public static final int event_index_2 = 1;
public static String event_name_3 = "생명체의 반란!!!";
public static String event_text_3 = "괴생명체가 갑자기 엄청나게 반항을 한다!!! 적절한 조치를 취할것인가???";
public static String event_result_yes_3 = "적절한 조치를 취했더니 오히려 반항이 거세졌다...";
public static String event_result_no_3 = "가만히 뒀더니 혼자 지쳐서 조용해졌다...";
public static final int event_index_3 = 2;
public static String event_name_4 = "갑자기 몸이 아프다!!!";
public static String event_text_4 = "몸이 갑자기 안좋다!!! 미심쩍은 물약을 먹을것인가???";
public static String event_result_yes_4 = "미심쩍은 물약이었지만 효과는 직방이었다!!!";
public static String event_result_no_4 = "몸이 안좋아져 생명체의 복종도가 많이 감소했다...";
public static final int event_index_4 = 3;
public static String event_name_5 = "지나가는 민간인!!!";
public static String event_text_5 = "지나가는 민간인이 있다!!! 먹이로 삼게 급습할것인가???";
public static String event_result_yes_5 = "알고보니 마동석 같은 사람이어서 된통 당하고 빌기까지 했다...";
public static String event_result_no_5 = "생명체가 인간고기를 못먹어 허기가 조금 감소했다...";
public static final int event_index_5 =4;
public static String event_name_6  = "야생동물의 탈출!!!";
public static String event_text_6 = "동물원에서 퓨마가 탈출해서 괴생명체를 급습했다!!! 괴생명체를 응원만 할 것인가???";
public static String event_result_yes_6 ="응원만 했더니 괴생명체가 삐져버렸다...";
public static String event_result_no_6 = "괴생명체를 도와줘서 같이 퓨마를 물리쳤더니 괴생명체의 복종도가 많이 증가했다!!!";
public static final int event_index_6 =5;
public static String event_name_7  = "수상쩍은 이웃!!!";
public static String event_text_7 = "수상쩍은 이웃이 이사왔다면서 떡을들고 집안에 들어오려 한다!!! 들어오는것을 허락할 것인가??? ";
public static String event_result_yes_7 ="기어다니는 혼돈... 니알라 토텝이어서 생명체의 스탯이 엉망진창이 되버렸다...";
public static String event_result_no_7 = "현명한 선택이라며 나에게 힘을 주고 갔다!!!";
public static final int event_index_7 =6;

/*
public static String event_name_8  = "";
public static String event_text_8 = "";
public static String event_result_yes_8 ="";
public static String event_result_no_8 = "";
public static final int event_index_8 = ;
*/
public static final int event_num =7;
public static final int ending_num =17;


public static final int yes = 0;
public static final int no =1;
creature my_creature;
no_job my_job;
event my_event;
String []ending_text_table = new String [ending_num];
event_vew vew;
//init할 때 호출해서 자신의 생명체와 자신의 직업을 초기화함
return_value r_v ;
class event_element
{
    String name;
    String text;
    String result_yes;
    String result_no;
    public event_element(String a, String b,String c, String d)
    {
        this.name =a;
        this.text = b;
        this.result_yes = c;
        this.result_no =d;
    }
}
//인터페이스에게 리턴할 발류임
public event_vew event_occur()
{
   /* int occur_or_not = 50;
    if(occur_or_not<(int)Math.random()*100)
    {
        return new event_element("아무일도 없다.","평소와 같다..."," "," ");
        //이벤트 발생안함
    }*/
	int temp_index;
    temp_index = (int)(Math.random()*event_num);
    /*return temp_index;*/
    return new event_vew(my_event.event_table[temp_index].name,my_event.event_table[temp_index].text,temp_index);

}
public return_value_event event_choice(int a, int temp_index) //0은 예 1은 아니오
{
    if(temp_index != -1 && temp_index <event_num)
    {
        switch(a)
        {
            case yes:
                switch(temp_index)
                {
                    case event_index_1:
                        my_creature.obedience *= (float)3/5;
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_yes_1);
                    case event_index_2:
                        my_creature.health *= (float)1/2;
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_yes_2);
                    case event_index_3:
                        my_creature.obedience *= (float)6/7;
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_yes_3);
                    case event_index_4:
                        my_creature.mental *=(float)6/5;
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_yes_4);
                    case event_index_5:
                        my_creature.obedience *=(float)1/2;
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_yes_5);
                    case event_index_6:
                        my_creature.mental*=(float)6/7;
                        my_creature.obedience *=(float)6/7;
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_yes_6);
                    case event_index_7:
                        int temp_hunger = my_creature.hunger;
                        int temp_health = my_creature.health;
                        int temp_mental = my_creature.mental;
                        int temp_obedience = my_creature.obedience;
                        int total_num;
                        total_num = (int)(Math.random()*10) +1;
                        for(int i=0;i<total_num;i++)
                        {
                            int temp_num = (int)(Math.random())*5;
                            switch(temp_num)
                            {
                                case 0:
                                    my_creature.hunger = my_creature.health;
                                    my_creature.health = temp_hunger;
                                    break;
                                case 1:
                                    my_creature.obedience = my_creature.mental;
                                    my_creature.mental = temp_obedience;
                                    break;
                                case 2:
                                    my_creature.mental = my_creature.hunger;
                                    my_creature.hunger = temp_mental;
                                    break;
                                case 3:
                                    my_creature.health = my_creature.obedience;
                                    my_creature.obedience = temp_health;
                                    break;
                                case 5:
                                    break;

                            }

                        }
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_yes_7);
      
                }

                break;

            case no:
                switch(temp_index)
                {
                    case event_index_1:
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_no_1);
                    case event_index_2:
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_no_2);
                    case event_index_3:
                        my_creature.mental *= (float)6/5;
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_no_3);
                    case event_index_4:
                        my_creature.obedience *=(float)3/10;
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_no_4);
                    case event_index_5:
                        my_creature.hunger *=(float)9/10;
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_no_5);
                    case event_index_6:
                        my_creature.obedience *=(float)3/2;
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_no_6);
                    case event_index_7:
                        my_job.cool_day = 0;
                        return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience,event_result_no_7);


                }


                break;


        }
    }
    return new return_value_event(my_creature.hunger,my_creature.mental,my_creature.health,my_creature.obedience," ");
}
class event
{
    event_element []event_table;//더 늘릴 수 있음
    int temp_index;
    public event()
    {
        event_table = new event_element[event_num];
        temp_index = -1; //발생 안했다는 뜻
        event_table[0] = new event_element(event_name_1,event_text_1,event_result_yes_1,event_result_no_1);
        event_table[1] = new event_element(event_name_2,event_text_2,event_result_yes_2,event_result_no_2);
        event_table[2] = new event_element(event_name_3,event_text_3,event_result_yes_3,event_result_no_3);
        event_table[3] = new event_element(event_name_4,event_text_4,event_result_yes_4,event_result_no_4);
        event_table[4] = new event_element(event_name_5,event_text_5,event_result_yes_5,event_result_no_5);
        event_table[5] = new event_element(event_name_6,event_text_6,event_result_yes_6,event_result_no_6);
        event_table[6] = new event_element(event_name_7,event_text_7,event_result_yes_7,event_result_no_7);

    }

 
    //문법 맞는지 모르겠음
    //여기에 이벤트 테이블
    //인터페이스에서 이벤트 클래스의 이벤트 호출함수를 호출하면 난수를 이용해 이벤트를 호출
    //인터페이스에서 뜬 다이얼로그 박스로 결과를 입력받아 스탯을 변경함
}
class creature
{
    int ending_stat = 1;
    int hunger = 0; //허기
    int health = 0; //건강
    int obedience = 0; //복종도
    int mental = 0; //정신건강
    public int type = 0;
    int ending_flag;
    public void set_ending_stat(int ending_stat)
    {
    	this.ending_stat = ending_stat;
    }
    public int stat_check()
    {
        if(ending_stat == 6)
        {
            switch(my_creature.type)
            {
                case pranc:
                    return clear_ending_pranc;
                case vamp :
                    return clear_ending_vamp;
                case zombie:
                    return clear_ending_zombie;
                default:

                    break;
            }
        }
        if(hunger <= 0 || health <=0 || obedience <= 0|| mental <= 0)
        {
            if(hunger<=0)
            {
                switch(type)
                {
                    case pranc:
                        return bad_ending_hunger_pranc;
                    case vamp:
                        return bad_ending_hunger_vamp;
                    case zombie:
                        return bad_ending_hunger_zombie;
                }
            }
            if(health<=0)
            {
                switch(type)
                {
                    case pranc:
                        return bad_ending_health_pranc;
                    case vamp:
                        return bad_ending_health_vamp;
                    case zombie:
                        return bad_ending_health_zombie;
                }
            }
            if(obedience<=0)
            {
                switch(type)
                {
                    case pranc:
                        return bad_ending_obedience_pranc;
                    case vamp:
                        return bad_ending_obedience_vamp;
                    case zombie:
                        return bad_ending_obedience_zombie;
                }
            }
            if(mental<=0)
            {
                switch(type)
                {
                    case pranc:
                        return bad_ending_mental_pranc;

                    case vamp:
                        return bad_ending_mental_vamp;

                    case zombie:
                        return bad_ending_mental_zombie;


                }
            }
            //생명체마다 0이된 스탯에 따라 다르게 엔딩 가능
            //여기서 0이된 엔딩에 따라 다르게 보내야함
        }
        return still_ok;
    }
    public void limit_restraint()
    {
        if(health>=100)
            health = 100;
        if(mental>=100)
            mental = 100;
        if(obedience>=100)
            obedience =100;
        if(hunger>=100)
            hunger =100;
    }
    public void stat_change(int a)
    {
        int decrease_hunger;
        int decrease_health;
        int decrease_mental;
        int decrease_obedience;
        switch(a)
        {
        case nodoing:
        	
        	break;
            case feed :
                my_creature.hunger +=5;
                my_creature.health+=3;
                break;
            case punish :
                my_creature.obedience+=5;
                my_creature.hunger+=3;
                break;
            case pet:
                my_creature.mental +=5;
                my_creature.health +=3;
                break;
            case syringe:
                my_creature.health+=5;
                my_creature.obedience+=3;
                break;
            case feed_trash:
                my_creature.hunger+=20;
                my_creature.obedience-=7;
                my_creature.health-=7;
                my_creature.mental-=7;
                break;
            case punish_harder:
                my_creature.obedience+=20;
                my_creature.hunger-=7;
                my_creature.health-=7;
                my_creature.mental-=7;
                break;
            case read_story:
                my_creature.mental+=20;
                my_creature.obedience-=7;
                my_creature.health-=7;
                my_creature.hunger-=7;
                break;
            case hard_training:
                my_creature.health+=20;
                my_creature.obedience-=7;
                my_creature.hunger-=7;
                my_creature.mental-=7;
                break;
            case ending:
                int decrease_rate = -20; //감소된 평균 감소량
                int temp_ending; //원래는 20%인데 평균감소량에따라 증가됨
                int ending_flag=-1;
                decrease_hunger = -20;
                decrease_health =-20;
                decrease_mental = -20;
                decrease_obedience = -20;

                if(decrease_health>-(my_creature.health)/2)
                {
                    decrease_health = -(my_creature.health)/2;
                }
                if(decrease_hunger>-(my_creature.hunger)/2)
                {
                    decrease_hunger = -(my_creature.hunger)/2;
                }
                if(decrease_mental>-(my_creature.mental)/2)
                {
                    decrease_mental= -(my_creature.mental)/2;
                }
                if(decrease_obedience>-(my_creature.obedience)/2)
                {
                    decrease_obedience= -(my_creature.obedience)/2;
                }

                my_creature.health +=decrease_health;
                my_creature.obedience +=decrease_obedience;
                my_creature.mental +=decrease_mental;
                my_creature.hunger+= decrease_hunger;

                decrease_rate = -(decrease_health+decrease_obedience+decrease_mental+decrease_hunger)/4;
              //  System.out.println(decrease_rate);
               // decrease_rate +=10;
                temp_ending = (int)(Math.random()*100)+1;
               // System.out.println(temp_ending);
                if(temp_ending < decrease_rate)
                {
                    ending_flag = 1;
                    my_creature.ending_stat+=1;
                } 
                else if (temp_ending>=decrease_rate)
                {
                    ending_flag = 0;
                }
                if(ending_flag==1)
                {
                    my_creature.health -= decrease_health / 3;
                    my_creature.obedience -= decrease_obedience / 3;
                    my_creature.mental -= decrease_mental / 3;
                    my_creature.hunger -= decrease_hunger / 3;
                    // 엔딩 성공에 따른 약간의 보상임
                    ending_flag = 0;
                } //복구
            	//my_creature.ending_stat++;
                //여기서 자신의 스탯의 25%를 소모하고 소모한 스탯에 따라 엔딩스탯이 증가함
                break;
            case special_doctor:
                my_creature.health = 99;
                break;
            case special_soldier:
                my_creature.obedience =99;
                break;

            case special_mentalist:
                my_creature.mental = 99;
                break;
            case special_farmer:
                my_creature.hunger = 99;
                break;
        }
    }
    public void stat_decrease()
    {
        switch(type)
        {
            case pranc:
                my_creature.hunger -= decrease_hunger_pranc;
                my_creature.obedience -= decrease_obedience_pranc;
                my_creature.mental-=decrease_mental_pranc;
                my_creature.health -=decrease_health_pranc;
                break;
            case vamp :
                my_creature.hunger -= decrease_hunger_vamp;
                my_creature.obedience -= decrease_obedience_vamp;
                my_creature.mental-= decrease_mental_vamp;
                my_creature.health -=decrease_health_vamp;
                break;
            case zombie:
                my_creature.hunger -= decrease_hunger_zombie;
                my_creature.obedience -= decrease_obedience_zombie;
                my_creature.mental-=decrease_mental_zombie;
                my_creature.health -=decrease_health_zombie;
                break;


        }



    }

}
class pranc extends creature
{

    public pranc(int hunger,int health,int obedience, int mental)
    {
        this.hunger = hunger;
        this.health = health;
        this.obedience = obedience;
        this.mental = mental;
    }

}
class vampire extends creature
{
    public vampire(int hunger,int health,int obedience, int mental)
    {
        this.hunger = hunger;
        this.health = health;
        this.obedience = obedience;
        this.mental = mental;
    }
}
class zombie extends creature
{
    public zombie(int hunger,int health,int obedience, int mental)
    {
        this.hunger = hunger;
        this.health = health;
        this.obedience = obedience;
        this.mental = mental;
    }

}
//생명체들
class no_job
{
    public int type;
    public int cool_day;
    public int flag;
    public no_job(){
        type =0;
        cool_day = 0;
        flag = 0;
    }
    public boolean cool_time_check()
    {
        //day는 기술을 쓰고 지난날들

        if(cool_day == 0)
        {
            flag = 1;
            cool_day++;
            return true;
        }
        if(cool_day >= 5)
        {
            cool_day = 0;
            return true;
        }
        else
        {
            return false;
        }
    }
    public void cool_time_increase()
    {
        if(flag == 1)
        {
            cool_day++;
        }
    }
    public void passive_adapt(int type)
    {

    }
}
class doctor extends no_job
{
    //여기다가 특수행동 정의
    //스탯 감소할 때 패시브함수 호출함
    public void passive_adapt(int type)
    {
        switch(type)
        {
            case pranc:
                decrease_health_pranc *=passive_rate;
                break;
            case vamp:
                decrease_health_vamp *=passive_rate;
                break;
            case zombie:
                decrease_health_zombie *=passive_rate;
                break;

        }
    }
}
class soldier extends no_job
{
    public void passive_adapt(int type)
    {
        switch(type)
        {
            case pranc:
                decrease_obedience_pranc *= passive_rate;
                break;
            case vamp:
                decrease_obedience_vamp *= passive_rate;
                break;
            case zombie:
                decrease_obedience_zombie *=passive_rate;
                break;

        }
    }
}
class farmer extends no_job
{
    public void passive_adapt(int type)
    {
        switch(type)
        {
            case pranc:
                decrease_hunger_pranc *= passive_rate;
                break;
            case vamp:
                decrease_hunger_vamp *= passive_rate;
                break;
            case zombie:
                decrease_hunger_zombie *= passive_rate;
                break;

        }
    }
}
class mentalist extends no_job
{
    public void passive_adapt(int type)
    {
        switch(type)
        {
            case pranc:
                decrease_mental_pranc *= passive_rate;
                break;
            case vamp:
                decrease_mental_vamp *=passive_rate;
                break;
            case zombie:
                decrease_mental_zombie *= passive_rate;
                break;

        }
    }
}
public return_value init_my_creature_job(int a,int b)
{
    switch(a)//생명체
    {
        case pranc :
            
            my_creature = new pranc(first_pranc_hunger,first_pranc_health,first_pranc_obedience,first_pranc_mental);
            my_creature.type =pranc;
            break;
        case vamp :
           
            my_creature = new vampire(first_vamp_hunger,first_vamp_health,first_vamp_obedience,first_vamp_mental);
            my_creature.type = vamp;
            break;
        case zombie:
           
            my_creature = new zombie(first_zombie_hunger,first_zombie_health,first_zombie_obedience,first_zombie_mental);
            my_creature.type = zombie;
            break;

    }
    switch (b)
    {
        case doctor:
           
            my_job = new doctor();
            my_job.type= doctor;
            my_job.cool_day = 0;
            my_job.passive_adapt(my_creature.type);
            break;
        case soldier:
           
            my_job = new soldier();
            my_job.type = soldier;
            my_job.cool_day = 0;
            my_job.passive_adapt(my_creature.type);//그냥 겹쳐서 넣었음
            break;
        case farmer:
          
            my_job = new farmer();
            my_job.type = farmer;
            my_job.cool_day = 0;
            my_job.passive_adapt(my_creature.type);
            break;

        case mentalist:
            my_job  = new mentalist();
            my_job.type = mentalist;
            my_job.cool_day = 0;
            my_job.passive_adapt(my_creature.type);
            break;
    }
    my_event = new event();
    ending_text_table[still_ok]=" ";
    ending_text_table[bad_ending_hunger_pranc] = "허기를 참지못해 자신의 신체파트를 다 물어뜯어 머리밖에 남지 않게 되었다...";
    ending_text_table[bad_ending_mental_pranc] = "자신의 흉측한 모습을 견디지 못해 심장을 뜯어서 터뜨려 버렸다...";
    ending_text_table[bad_ending_health_pranc] = "각 신체들이 작동을 중지하고 녹아내려 흐물흐물하게 되어 버렸다...";
    ending_text_table[bad_ending_obedience_pranc] = "자신을 이렇게 만든 박사를 저주하며 박사도 괴물과 같은 모습으로 만들어 버렸다...";
    ending_text_table[clear_ending_pranc] = "무덤을 지키는 무덤지기가 되어 늦은 저녁 찾아오는 유가족을 뜯어먹는 괴물이 되었다!!!";
    ending_text_table[bad_ending_hunger_vamp] = "굶주림을 참지못해 박사의 피를 마셨으나 오염된 피라서 식중독으로 쓰러졌다...";
    ending_text_table[bad_ending_mental_vamp] = "완벽한 뱀파이어가 되는것에 싫증을 느끼고 동굴로 돌아가 버렸다...";
    ending_text_table[bad_ending_health_vamp] = "건강이 악화되어 시름시름 앓다가 재가되어 사라졌다...";
    ending_text_table[bad_ending_obedience_vamp] = "박사의 거처를 탈출하자 마자 태양을 직시해 끔찍한 비명을 지르며 신체가 서서히 중심부로 압축되어 공이되어 터져버렸다...";
    ending_text_table[clear_ending_vamp] = "완벽한 뱀파이어가 되며 성에서 숨어 살며 성근처의 행인들의 피를 빠는 괴물이 되었다!!!";
    ending_text_table[bad_ending_hunger_zombie] = "굶주림을 참지못한 좀비가 박사를 먹어버렸다...";
    ending_text_table[bad_ending_mental_zombie] = "좀비가 참지 못해 서로를 미친듯이 물어뜯어 부패된 시체밖에 남지 않게되었다...";
    ending_text_table[bad_ending_health_zombie]  ="좀비의 시체가 썩어 문드러져 더이상 움직이지 못하게 되었다...";
    ending_text_table[bad_ending_obedience_zombie] = "좀비가 박사의 지배를 벗어나 주거지를 탈출해 버렸다...";
    ending_text_table[clear_ending_zombie] = "32마리의 정예 좀비가 도시를 습격하여 점차 세력을 확장해 인류의 90%가 줄어들었다!!!";
    ending_text_table[bad_over_ending] = "나에게 주어진 모든시간을 다써버렸다...";
    r_v = new return_value(my_creature.ending_stat,still_ok,my_creature.hunger,my_creature.health,my_creature.obedience,my_creature.mental,1,ending_text_table[still_ok]);
    return r_v;

}
public boolean cool_check()
{
	return my_job.cool_time_check();
}
public boolean event_check()
{
	 int occur_or_not = 25;
	 
     if(occur_or_not<(int)(Math.random()*100))
     {
    	 //System.out.println("true");
         return true;
         //이벤트 발생안함
     }
    // System.out.println("false");
     return false;
}
public return_value load_my_creature(int monster,int job, int hunger,int health,int obedience,int mental,int day, int ending)
{
	
	 switch(monster +1)//생명체
	    {
	
	        case pranc :
	        	
	            my_creature = new pranc(hunger,health,mental,obedience);
	            my_creature.type =pranc;
	            break;
	        case vamp :
	           
	            my_creature = new vampire(hunger,health,mental,obedience);
	            my_creature.type = vamp;
	            break;
	        case zombie:
	           
	            my_creature = new zombie(hunger,health,mental,obedience);
	            my_creature.type = zombie;
	            break;

	    }
	 	my_creature.set_ending_stat(ending);
	    switch (job+1)
	    {
	        case doctor:
	           
	            my_job = new doctor();
	            my_job.type= doctor;
	            my_job.cool_day = 0;//로딩특전!!!!!
	            my_job.passive_adapt(my_creature.type);
	            break;
	        case soldier:
	           
	            my_job = new soldier();
	            my_job.type = soldier;
	            my_job.cool_day = 0;
	            my_job.passive_adapt(my_creature.type);//그냥 겹쳐서 넣었음
	            break;
	        case farmer:
	          
	            my_job = new farmer();
	            my_job.type = farmer;
	            my_job.cool_day = 0;
	            my_job.passive_adapt(my_creature.type);
	            break;

	        case mentalist:
	            my_job  = new mentalist();
	            my_job.type = mentalist;
	            my_job.cool_day = 0;
	            my_job.passive_adapt(my_creature.type);
	            break;
	    }
	    r_v = new return_value(my_creature.ending_stat,still_ok,my_creature.hunger,my_creature.health,my_creature.obedience,my_creature.mental,day,ending_text_table[still_ok]);
        return r_v;
}
public return_value game_play(int[]a, int b, int day)//행동을 저장하고 있는 a 배열  b에 엔딩 행동 플래그 및 특수행동 플래그 //쿨타임계산함수 필요 day : 현재 지난 날들
{
    int ending_flag;
    //System.out.printf("%d\n", day);
    if(day == 30)
    {
    	//  System.out.printf("%d\n", day);
    	ending_flag = bad_over_ending;
    	 r_v = new return_value(my_creature.ending_stat,ending_flag,my_creature.hunger,my_creature.health,my_creature.obedience,my_creature.mental,day,ending_text_table[ending_flag]);
         return r_v;
    }
    if(b==1)//엔딩임
    {
        my_creature.stat_change(a[0]);
    }
    if(b==2)//특수행동
    {
        my_creature.stat_change(a[0]);
        day++;
        r_v = new return_value(my_creature.ending_stat,still_ok,my_creature.hunger,my_creature.health,my_creature.obedience,my_creature.mental,day,ending_text_table[still_ok]);
        return r_v;
    }
    else if(b ==0)
    {
        for (int i = 0; i < 3; i++)
        {
            my_creature.stat_change(a[i]);
        }
        //행동 배열을 입력받아서 스탯을 변경함
        my_creature.stat_decrease();
    }
    my_job.cool_time_increase();
    my_creature.limit_restraint();
    ending_flag = my_creature.stat_check();
    //System.out.printf("%d\n", ending_flag);
    r_v = new return_value(my_creature.ending_stat,ending_flag,my_creature.hunger,my_creature.health,my_creature.obedience,my_creature.mental,++day,ending_text_table[ending_flag]);
    return r_v;
}
}