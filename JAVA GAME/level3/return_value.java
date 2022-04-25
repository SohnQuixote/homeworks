package level3;

public class return_value
{
	int ending_step;
    int ending_flag;
    int hunger;
    int mental;
    int health;
    int obedience;
    int day;
    String text; //엔딩시 출력되는 텍스트임
    public return_value(int ending_step,int ending_flag,int hunger, int health, int obedience,int mental,int day,String text)
    {
    	this.ending_step = ending_step;
        this.ending_flag = ending_flag;
        this.hunger = hunger;
        this.mental = mental;
        this.health = health;
        this.obedience = obedience;
        this.day = day;
        this.text  = text;
    }
    public return_value()
    {
    	
    }
}
