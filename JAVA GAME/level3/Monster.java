package level3;

public class Monster {//하나의 생명체를 담는 생명체
	
	private String monsterChooseImage;//게임 선택 창 표지 이미지 생명체를 선택하는
	private String monsterSelectedImage; // 게임이 실행됬을때의 현재 이미지(단계별 표시)
	private String gameImage;// 해당 곡을 실행했을때 표지 이미지

	private String gameMusic;//해당 곡을 실행했을 떄 음악

	private Integer hunger;//허기
	private Integer obedience;//복종도
	private Integer health;//건강
	private Integer mental;//정신건강
	private Integer day;
	private static Integer endingCondition= 1;//초기 모양 

	
	public String getMonsterSelectedImage() {
		//System.out.println(this.endingCondition);
		return monsterSelectedImage+endingCondition+".png";
	}
	public void setMonsterSelectedImage(String monsterSelectedImage) {
		this.monsterSelectedImage = monsterSelectedImage;
	}
	
	public Integer getEndingCondition() {
		return endingCondition;
	}
	public void setEndingCondition(Integer endingCondition) {
		this.endingCondition = endingCondition;
		//System.out.println(this.endingCondition);
	}
	
	public void initHunger(Integer hunger) {
		this.hunger = hunger;
	}
	public Integer getHunger() {
		return hunger;
	}
	public void setHunger(Integer hunger) {
		this.hunger -=hunger;
	}
	
	public void initObedience(Integer obedience) {
		this.obedience = obedience;
	}
	public Integer getObedience() {
		return obedience;
	}
	public void setObedience(Integer obedience) {
		this.obedience -= obedience;
	}
	
	public void initHealth(Integer health) {
		this.health = health;
	}
	public Integer getHealth() {
		return health;
	}
	public void setHealth(Integer health) {
		this.health -=health;
	}
	
	public void initMental(Integer mental) {
		this.mental = mental;
	}
	public Integer getMental() {
		return mental;
	}
	public void setMental(Integer mental) {
		this.mental -= mental;
	}
	
	public String getMonsterChooseImage() {
		return monsterChooseImage;
	}
	public void setMonsterChooseImage(String startImage) {
		this.monsterChooseImage = startImage;
	}
	public String getGameImage() {
		return gameImage;
	}
	public void setGameImage(String gameImage) {
		this.gameImage = gameImage;
	}


	public String getGameMusic() {
		return gameMusic;
	}
	public void setGameMusic(String gameMusic) {
		this.gameMusic = gameMusic;
	}
	
	public Monster(String monsterChooseImage, String gameImage, String gameMusic, String monsterSelectedImge) {
		super();
		this.monsterChooseImage = monsterChooseImage;
		this.gameImage = gameImage;
		this.gameMusic = gameMusic;
		this.monsterSelectedImage = monsterSelectedImge;
	}
	
	
}
