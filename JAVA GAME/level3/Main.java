package level3;

public class Main {
	public static final int SCREEN_WIDTH = 1280;
	public static final int SCREEN_HEIGHT = 720;
	
	//생명체
	public static final int CHOOSE_FRANKEN = 0;
	public static final int CHOOSE_DRACULA = 1;
	public static final int CHOOSE_ZOOMBIE = 2;
	
	//전직
	public static final int CHOOSE_DOCTOR = 0;
	public static final int CHOOSE_FARMER = 1;
	public static final int CHOOSE_SOLDIER = 2;
	public static final int CHOOSE_PSYCHOLOGIST = 3;
	
	//리스크가 없는 행동
	public static final int ACTION_FEED = 0;
	public static final int ACTION_CANE = 1;
	public static final int ACTION_PAT = 2;
	public static final int ACTION_SHOT = 3;
	
	//리스크가 있는 행동
	public static final int ACTION_FEEDTRASH = 4;
	public static final int ACTION_PUNISHMENT = 5;
	public static final int ACTION_FAIRYSTORY = 6;
	public static final int ACTION_TRAINING = 7;
	
	//특수행동
	 public final static int SPECIAL_DOCTOR =8;//의사
	 public final static int SPECIAL_FARMER=9;//농부
	 public final static int SPECIAL_SOLDIER =10;//군인
	 public final static int SPECIAL_PSYCHIATRIST =11;//정신과의사
	
	//엔딩행동
	public static final int ENDING_ACTION_FRANKEN = 12;
	public static final int ENDING_ACTION_DRACULA = 13;
	public static final int ENDING_ACTION_ZOMBIE = 14;
	
    //생명체에 따른 초기스탯들
    public final static int first_pranken_hunger =20;
    public final static int first_pranken_health = 25;
    public final static int first_pranken_mental = 40;
    public final static int first_pranken_obedience = 35;
    
    public final static int first_dracula_hunger =30;
    public final static int first_dracula_health = 20;
    public final static int first_dracula_mental = 30;
    public final static int first_dracula_obedience  =40;
    
    public final static int first_zombie_hunger =40;
    public final static int first_zombie_health =25;
    public final static int first_zombie_mental = 20;
    public final static int first_zombie_obedience = 30;

    //생명체에 따른 감소량
    public static int decrease_hunger_pranken = 4;
    public static int decrease_health_pranken  =3;
    public static int decrease_mental_pranken = 6;
    public static int decrease_obedience_pranken = 5;
    
    public static int decrease_hunger_dracula =4;
    public static int decrease_health_dracula =2;
    public static int decrease_mental_dracula =4;
    public static int decrease_obedience_dracula =8;
    
    public static int decrease_hunger_zombie = 7;
    public static int decrease_health_zombie = 3;
    public static int decrease_mental_zombie =2;
    public static int decrease_obedience_zombie = 4;
	
	public static void main(String[] args) {
		
		new IntroFrame();
	}


}
