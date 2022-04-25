package level3;

import java.awt.Color;
import java.io.*;
import java.awt.Cursor;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.util.ArrayList;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

public class IntroFrame extends JFrame{
	
	private Image screenImage;
	private Graphics screenGraphic;
	
	private Image background =  new ImageIcon(Main.class.getResource("../images/introBackground.png")).getImage();
	private Image actionBar =  new ImageIcon(Main.class.getResource("../images/ActionBar.png")).getImage();
	private Image statBar =  new ImageIcon(Main.class.getResource("../images/StatBar.png")).getImage();
	private Image monsterImage = new ImageIcon(Main.class.getResource("../images/frankenPhase1.png")).getImage();
	private Image actionMenuBar = new ImageIcon(Main.class.getResource("../images/actionMenuBar.png")).getImage();
	private Image goodEndingFranken = new ImageIcon(Main.class.getResource("../images/frankenGoodEnding.png")).getImage();
	private Image goodEndingDracula = new ImageIcon(Main.class.getResource("../images/draculaGoodEnding.png")).getImage();
	private Image goodEndingZombie = new ImageIcon(Main.class.getResource("../images/zombieGoodEnding.jpg")).getImage();
	
	private JLabel menuBar = new JLabel(new ImageIcon(Main.class.getResource("../images/menuBar.png")));
	
	private ImageIcon exitButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/exitButtonEntered.png"));
	private ImageIcon exitButtonBasicImage = new ImageIcon(Main.class.getResource("../images/exitButtonBasic.png"));
	private ImageIcon lodingButtonBasicImage = new ImageIcon(Main.class.getResource("../images/lodingButtonBasic.png"));
	private ImageIcon lodingButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/lodingButtonEntered.png"));
	private ImageIcon startButtonBasicImage = new ImageIcon(Main.class.getResource("../images/startButtonBasic.png"));
	private ImageIcon startButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/startButtonEntered.png"));
	private ImageIcon quitButtonBasicImage = new ImageIcon(Main.class.getResource("../images/quitButtonBasic.png"));
	private ImageIcon quitButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/quitButtonEntered.png"));
	private ImageIcon rightButtonBasicImage = new ImageIcon(Main.class.getResource("../images/right.png"));
	private ImageIcon rightButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/rightEntered.png"));
	private ImageIcon leftButtonBasicImage = new ImageIcon(Main.class.getResource("../images/left.png"));
	private ImageIcon leftButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/leftEntered.png"));
	private ImageIcon nextButtonBasicImage = new ImageIcon(Main.class.getResource("../images/nextButtonBasic.png"));
	private ImageIcon nextButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/nextButtonEntered.png"));
	private ImageIcon menuButtonBasicImage = new ImageIcon(Main.class.getResource("../images/menuButtonBasic.png"));
	private ImageIcon menuButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/menuButtonEntered.png"));
	private ImageIcon statButtonBasicImage = new ImageIcon(Main.class.getResource("../images/statButtonBasic.png"));
	private ImageIcon statButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/statButtonEntered.png"));
	private ImageIcon saveButtonBasicImage = new ImageIcon(Main.class.getResource("../images/saveButtonBasic.png"));
	private ImageIcon saveButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/saveButtonEntered.png"));
	private ImageIcon backButtonBasicImage = new ImageIcon(Main.class.getResource("../images/backButtonBasic.png"));
	private ImageIcon backButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/backButtonEntered.png"));
	private ImageIcon eatFoodButtonBasicImage = new ImageIcon(Main.class.getResource("../images/eatFoodButtonBasic.png"));
	private ImageIcon eatFoodButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/eatFoodButtonEntered.png"));
	private ImageIcon caneButtonBasicImage = new ImageIcon(Main.class.getResource("../images/caneButtonBasic.png"));
	private ImageIcon caneButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/caneButtonEntered.png"));
	private ImageIcon patButtonBasicImage = new ImageIcon(Main.class.getResource("../images/patButtonBasic.png"));
	private ImageIcon patButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/patButtonEntered.png"));
	private ImageIcon shotButtonBasicImage = new ImageIcon(Main.class.getResource("../images/shotButtonBasic.png"));
	private ImageIcon shotButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/shotButtonEntered.png"));
	private ImageIcon eatTrushButtonBasicImage = new ImageIcon(Main.class.getResource("../images/eatTrashButtonBasic.png"));
	private ImageIcon eatTrushButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/eatTrashButtonEntered.png"));
	private ImageIcon punishmentButtonBasicImage = new ImageIcon(Main.class.getResource("../images/punishmentButtonBasic.png"));
	private ImageIcon punishmentButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/punishmentButtonEntered.png"));
	private ImageIcon fairyButtonBasicImage = new ImageIcon(Main.class.getResource("../images/fairyButtonBasic.png"));
	private ImageIcon fairyButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/fairyButtonEntered.png"));
	private ImageIcon trainingButtonBasicImage = new ImageIcon(Main.class.getResource("../images/trainingButtonBasic.png"));
	private ImageIcon trainingButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/trainingButtonEntered.png"));
	private ImageIcon actionDoButtonBasicImage = new ImageIcon(Main.class.getResource("../images/actionDoButtonBasic.png"));
	private ImageIcon actionDoButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/actionDoButtonEntered.png"));
	private ImageIcon actionCancelButtonBasicImage = new ImageIcon(Main.class.getResource("../images/actionCancelButtonBasic.png"));
	private ImageIcon actionCancelButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/actionCancelButtonEntered.png"));
	private ImageIcon specialButtonBasicImage = new ImageIcon(Main.class.getResource("../images/specialButtonBasic.png"));
	private ImageIcon specialButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/specialButtonEntered.png"));
	private ImageIcon endingFrankenButtonBasicImage = new ImageIcon(Main.class.getResource("../images/endingFrankenButtonBasic.png"));
	private ImageIcon endingFrankenButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/endingFrankenButtonEntered.png"));
	private ImageIcon endingDraculaButtonBasicImage = new ImageIcon(Main.class.getResource("../images/endingDraculaButtonBasic.png"));
	private ImageIcon endingDraculaButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/endingDraculaButtonEntered.png"));
	private ImageIcon endingZombieButtonBasicImage = new ImageIcon(Main.class.getResource("../images/endingZombieButtonBasic.png"));
	private ImageIcon endingZombieButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/endingZombieButtonEntered.png"));
	private ImageIcon specialDoctorButtonBasicImage = new ImageIcon(Main.class.getResource("../images/specialDoctorButtonBasic.png"));
	private ImageIcon specialDoctorButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/specialDoctorButtonEntered.png"));
	private ImageIcon specialSoldierButtonBasicImage = new ImageIcon(Main.class.getResource("../images/specialSoldierButtonBasic.png"));
	private ImageIcon specialSoldierButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/specialSoldierButtonEntered.png"));
	private ImageIcon specialPsychiatristButtonBasicImage = new ImageIcon(Main.class.getResource("../images/specialPsychiatristButtonBasic.png"));
	private ImageIcon specialPsychiatristButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/specialPsychiatristButtonEntered.png"));
	private ImageIcon specialFarmerButtonBasicImage = new ImageIcon(Main.class.getResource("../images/specialFarmerButtonBasic.png"));
	private ImageIcon specialFarmerButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/specialFarmerButtonEntered.png"));
	private ImageIcon undeterminedImage = new ImageIcon(Main.class.getResource("../images/UndeterminedImage.png"));
	
	private JLabel statHunger = new JLabel();
	private JLabel statObedience = new JLabel();
	private JLabel statHealth = new JLabel();
	private JLabel statMental = new JLabel();
	private JLabel endingStat = new JLabel();
	private JLabel statDay  =new JLabel();
	private JLabel ending_text = new JLabel();
	//쿨데이 넣으면 좋을거 같음
	
	private JButton exitBtn = new JButton(exitButtonBasicImage);
	private JButton startBtn = new JButton(startButtonBasicImage);
	private JButton lodingBtn = new JButton(lodingButtonBasicImage);
	private JButton quitBtn = new JButton(quitButtonBasicImage);
	private JButton monsterRightBtn = new JButton(rightButtonBasicImage);
	private JButton monsterLeftBtn = new JButton(leftButtonBasicImage);
	private JButton jobRightBtn = new JButton(rightButtonBasicImage);
	private JButton jobLeftBtn = new JButton(leftButtonBasicImage);	
	private JButton nextBtn = new JButton(nextButtonBasicImage);
	private JButton actionBtn = new JButton(menuButtonBasicImage);
	private JButton statBtn = new JButton(statButtonBasicImage);
	private JButton saveBtn = new JButton(saveButtonBasicImage);
	private JButton specialBtn = new JButton(specialButtonBasicImage);
	private JButton backBtn = new JButton(backButtonBasicImage);
	
	private JButton feedBtn = new JButton(eatFoodButtonBasicImage);
	private JButton caneBtn = new JButton(caneButtonBasicImage);
	private JButton patBtn = new JButton(patButtonBasicImage);
	private JButton shotBtn = new JButton(shotButtonBasicImage);
	private JButton feedTrushBtn = new JButton(eatTrushButtonBasicImage);
	private JButton punishmentBtn = new JButton(punishmentButtonBasicImage);
	private JButton fairyBtn = new JButton(fairyButtonBasicImage);
	private JButton trainingBtn = new JButton(trainingButtonBasicImage);
	private JButton endingFrankenBtn = new JButton(endingFrankenButtonBasicImage);
	private JButton endingDraculaBtn = new JButton(endingDraculaButtonBasicImage);
	private JButton endingZombieBtn = new JButton(endingZombieButtonBasicImage);
	private JButton special_doctor_btn = new JButton(specialDoctorButtonBasicImage);
	private JButton special_farmer_btn = new JButton(specialFarmerButtonBasicImage);
	private JButton special_soldier_btn = new JButton(specialSoldierButtonBasicImage);
	private JButton special_mentalist_btn = new JButton(specialPsychiatristButtonBasicImage);
	
	private JButton actionDoBtn = new JButton(actionDoButtonBasicImage);
	private JButton actionCancelBtn = new JButton(actionCancelButtonBasicImage);

	private int mouseX,mouseY;
	
	private boolean isMainScreen = false;
	private boolean isGameScreen = false;
	private boolean isActionShow = false;
	private boolean isStatShow = false;
	private boolean isSpecialActionShow = false;
	private boolean isGameOver = false;

	
	ArrayList<Monster> monsterList = new ArrayList<Monster>();
	ArrayList<Job> jobList = new ArrayList<Job>();
	JLabel[] chooseActionImage = new JLabel[3];
	int[] actionList = new int[3];
	//sumin
	int[] action_list = new int[3];
	int ending_flag = 0;
	maingame game_data = new maingame();
	return_value game_stat = new return_value();
	return_value_event game_event = new return_value_event();
	event_vew event_view = new event_vew("","",0);
	int day = 0;
	//sumin
	private Image selectedMonsterImage;
	private Image selectedJobImage;

	private int nowSelectedMonster =0;
	private int nowSelectedJob = 0;
	private int actionIndex = -1;//행동을 아무것도 선택하지 않았음.
		
	private Music introMusic = new Music("Ticker.mp3",true);
	private Music selectedMusic;
	
	public IntroFrame() {
		
		setUndecorated(true);
		setSize(Main.SCREEN_WIDTH, Main.SCREEN_HEIGHT);
		setResizable(false);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
		setBackground(new Color(0,0,0,0));
		setLayout(null);
		

		introMusic.start();
		
		monsterList.add(new Monster("franken.png","frankenGame.png","frankenMusic.mp3","frankenPhase"));
		monsterList.add(new Monster("dracula.png","draculaGame.png","draculaMusic.mp3","bloodPhase"));
		monsterList.add(new Monster("zombie.png","zombieGame.png","zombieMusic.mp3","zombiePhase"));
		
		for(int i =0 ;i<3; i++) {
			chooseActionImage[i] = new JLabel(undeterminedImage);
		}
		
		jobList.add(new Job("doctor.png"));
		jobList.add(new Job("farmer.png"));
		jobList.add(new Job("soldier.png"));
		jobList.add(new Job("psychiatrist.png"));
		
		exitBtn.setBounds(1245, 1, 32, 32);
		exitBtn.setBorderPainted(false);
		exitBtn.setContentAreaFilled(false);
		exitBtn.setFocusPainted(false);
		exitBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				exitBtn.setIcon(exitButtonEnteredImage);
				exitBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				exitBtn.setIcon(exitButtonBasicImage);
				exitBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				
				System.exit(0);
			}
		});
		
		add(exitBtn);
		
		startBtn.setBounds(520, 250, 240, 120);
		startBtn.setBorderPainted(false);
		startBtn.setContentAreaFilled(false);
		startBtn.setFocusPainted(false);
		startBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				startBtn.setIcon(startButtonEnteredImage);
				startBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			
			}
			public void mouseExited(MouseEvent e) {
				startBtn.setIcon(startButtonBasicImage);
				startBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//시작하기 이벤트
				enterMain();
			}
		});
		
		add(startBtn);
		
		lodingBtn.setBounds(520, 350, 240, 120);
		lodingBtn.setBorderPainted(false);
		lodingBtn.setContentAreaFilled(false);
		lodingBtn.setFocusPainted(false);
		lodingBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				lodingBtn.setIcon(lodingButtonEnteredImage);
				lodingBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
				//불러오기 이벤트
			}
			public void mouseExited(MouseEvent e) {
				lodingBtn.setIcon(lodingButtonBasicImage);
				lodingBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//System.out.println("dd");
				//File*
				introMusic.close();
				game_load();
				gameLoad(temp_now_selected_monster,temp_now_selected_job);
			}
		});
		
		add(lodingBtn);
		
		quitBtn.setBounds(520, 450, 240, 120);
		quitBtn.setBorderPainted(false);
		quitBtn.setContentAreaFilled(false);
		quitBtn.setFocusPainted(false);
		quitBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				quitBtn.setIcon(quitButtonEnteredImage);
				quitBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				quitBtn.setIcon(quitButtonBasicImage);
				quitBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				System.exit(0);
			}
		});
		
		add(quitBtn);
		
		monsterLeftBtn.setBounds(250, 510, 64, 64);
		monsterLeftBtn.setBorderPainted(false);
		monsterLeftBtn.setContentAreaFilled(false);
		monsterLeftBtn.setFocusPainted(false);
		monsterLeftBtn.setVisible(false);
		monsterLeftBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				monsterLeftBtn.setIcon(leftButtonEnteredImage);
				monsterLeftBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				monsterLeftBtn.setIcon(leftButtonBasicImage);
				monsterLeftBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//왼쪽버튼 이벤트
				selectMonsterLeft();
			}
		});
		
		add(monsterLeftBtn);
		
		monsterRightBtn.setBounds(430, 510, 64, 64);
		monsterRightBtn.setBorderPainted(false);
		monsterRightBtn.setContentAreaFilled(false);
		monsterRightBtn.setFocusPainted(false);
		monsterRightBtn.setVisible(false);
		monsterRightBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				monsterRightBtn.setIcon(rightButtonEnteredImage);
				monsterRightBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				monsterRightBtn.setIcon(rightButtonBasicImage);
				monsterRightBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//오른쪽버튼 이벤트
				selectMonsterRight();
			}
		});
		
		add(monsterRightBtn);
		
		jobRightBtn.setBounds(930, 510, 64, 64);
		jobRightBtn.setBorderPainted(false);
		jobRightBtn.setContentAreaFilled(false);
		jobRightBtn.setFocusPainted(false);
		jobRightBtn.setVisible(false);
		jobRightBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				jobRightBtn.setIcon(rightButtonEnteredImage);
				jobRightBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				jobRightBtn.setIcon(rightButtonBasicImage);
				jobRightBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//오른쪽버튼 이벤트
				selectJobRight();
			}
		});
		
		add(jobRightBtn);
		
		jobLeftBtn.setBounds(750, 510, 64, 64);
		jobLeftBtn.setBorderPainted(false);
		jobLeftBtn.setContentAreaFilled(false);
		jobLeftBtn.setFocusPainted(false);
		jobLeftBtn.setVisible(false);
		jobLeftBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				jobLeftBtn.setIcon(leftButtonEnteredImage);
				jobLeftBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				jobLeftBtn.setIcon(leftButtonBasicImage);
				jobLeftBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//오른쪽버튼 이벤트
				selectJobLeft();
			}
		});
		
		add(jobLeftBtn);
		
		nextBtn.setBounds(1130, 640, 80, 80);
		nextBtn.setBorderPainted(false);
		nextBtn.setContentAreaFilled(false);
		nextBtn.setFocusPainted(false);
		nextBtn.setVisible(false);
		nextBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				nextBtn.setIcon(nextButtonEnteredImage);
				nextBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				nextBtn.setIcon(nextButtonBasicImage);
				nextBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//본격적인 게임 시작
				introMusic.close();
				
				gameStart(nowSelectedMonster, nowSelectedJob);
				
				
			}
		});
		
		add(nextBtn);
		
		actionBtn.setBounds(-10, 90, 210, 70);
		actionBtn.setBorderPainted(false);
		actionBtn.setContentAreaFilled(false);
		actionBtn.setFocusPainted(false);
		actionBtn.setVisible(false);
		actionBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				actionBtn.setBounds(-10, 90, 260, 80);
				actionBtn.setIcon(menuButtonEnteredImage);
				actionBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				actionBtn.setBounds(-10, 90, 210, 70);
				actionBtn.setIcon(menuButtonBasicImage);
				
				actionBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//행동선택 이미지 나옴
				ActionListShow();
			}
		});
		
		add(actionBtn);
		
		statBtn.setBounds(-10, 165, 210, 70);
		statBtn.setBorderPainted(false);
		statBtn.setContentAreaFilled(false);
		statBtn.setFocusPainted(false);
		statBtn.setVisible(false);
		statBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				statBtn.setBounds(-10, 165, 260, 80);
				statBtn.setIcon(statButtonEnteredImage);
				statBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				statBtn.setBounds(-10, 165, 210, 70);
				statBtn.setIcon(statButtonBasicImage);
				
				statBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//스탯이미지 나옴
				StatListShow();
			}
		});
		
		add(statBtn);
		
		
		specialBtn.setBounds(-10, 240, 215, 75);
		specialBtn.setBorderPainted(false);
		specialBtn.setContentAreaFilled(false);
		specialBtn.setFocusPainted(false);
		specialBtn.setVisible(false);
		specialBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				specialBtn.setBounds(-10, 240, 260, 80);
				specialBtn.setIcon(specialButtonEnteredImage);
				specialBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				specialBtn.setBounds(-10, 240, 215, 75);
				specialBtn.setIcon(specialButtonBasicImage);
				
				specialBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//특수 행동 버튼
				specialActionListShow();
			}
		});
		
		saveBtn.setBounds(-10, 315, 210, 70);
		saveBtn.setBorderPainted(false);
		saveBtn.setContentAreaFilled(false);
		saveBtn.setFocusPainted(false);
		saveBtn.setVisible(false);
		saveBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				saveBtn.setBounds(-10, 315, 260, 80);
				saveBtn.setIcon(saveButtonEnteredImage);
				saveBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				saveBtn.setBounds(-10, 315, 210, 70);
				saveBtn.setIcon(saveButtonBasicImage);
				
				saveBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//저장 이벤트
				game_save();	
			}
		});
		
		add(saveBtn);
		add(specialBtn);
		
		feedBtn.setBounds(-60, 190, 600, 50);
		feedBtn.setBorderPainted(false);
		feedBtn.setContentAreaFilled(false);
		feedBtn.setFocusPainted(false);
		feedBtn.setVisible(false);
		feedBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				feedBtn.setBounds(-60, 190, 600, 50);
				feedBtn.setIcon(eatFoodButtonEnteredImage);
				feedBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				feedBtn.setBounds(-60, 190, 600, 50);
				feedBtn.setIcon(eatFoodButtonBasicImage);
				
				feedBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//먹는 행동을 선택했다는 것을 체크하기 
				addAction(Main.ACTION_FEED,feedBtn.getIcon());
				
			}
		});
		
		add(feedBtn);
				
		caneBtn.setBounds(-60, 240, 600, 50);
		caneBtn.setBorderPainted(false);
		caneBtn.setContentAreaFilled(false);
		caneBtn.setFocusPainted(false);
		caneBtn.setVisible(false);
		caneBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				caneBtn.setBounds(-60, 240, 600, 50);
				caneBtn.setIcon(caneButtonEnteredImage);
				caneBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				caneBtn.setBounds(-60, 240, 600, 50);
				caneBtn.setIcon(caneButtonBasicImage);
				
				caneBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//회초리 행동을 선택함
				addAction(Main.ACTION_CANE,caneBtn.getIcon());
			}
		});
		
		add(caneBtn);
			
		patBtn.setBounds(-60, 290, 600, 50);
		patBtn.setBorderPainted(false);
		patBtn.setContentAreaFilled(false);
		patBtn.setFocusPainted(false);
		patBtn.setVisible(false);
		patBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				patBtn.setBounds(-60, 290, 600, 50);
				patBtn.setIcon(patButtonEnteredImage);
				patBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				patBtn.setBounds(-60, 290, 600, 50);
				patBtn.setIcon(patButtonBasicImage);
				
				patBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//쓰다듬기 행동을 함.
				addAction(Main.ACTION_PAT,patBtn.getIcon());
			}
		});
		
		add(patBtn);
		
		shotBtn.setBounds(-60, 340, 600, 50);
		shotBtn.setBorderPainted(false);
		shotBtn.setContentAreaFilled(false);
		shotBtn.setFocusPainted(false);
		shotBtn.setVisible(false);
		shotBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				shotBtn.setBounds(-60, 340, 600, 50);
				shotBtn.setIcon(shotButtonEnteredImage);
				shotBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				shotBtn.setBounds(-60, 340, 600, 50);
				shotBtn.setIcon(shotButtonBasicImage);
				
				shotBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//주사 놔주기 행동을 선택했다는 것을 체크하기 
				addAction(Main.ACTION_SHOT,shotBtn.getIcon());
			}
		});
		
		add(shotBtn);
		
		feedTrushBtn.setBounds(-60, 390, 600, 50);
		feedTrushBtn.setBorderPainted(false);
		feedTrushBtn.setContentAreaFilled(false);
		feedTrushBtn.setFocusPainted(false);
		feedTrushBtn.setVisible(false);
		feedTrushBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				feedTrushBtn.setBounds(-60, 390, 600, 50);
				feedTrushBtn.setIcon(eatTrushButtonEnteredImage);
				feedTrushBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				feedTrushBtn.setBounds(-60, 390, 600, 50);
				feedTrushBtn.setIcon(eatTrushButtonBasicImage);
				
				feedTrushBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//쓰레기 먹이기 행동을 선택함
				addAction(Main.ACTION_FEEDTRASH,feedTrushBtn.getIcon());
			}
		});
		
		add(feedTrushBtn);
		
		punishmentBtn.setBounds(-60, 440, 600, 50);
		punishmentBtn.setBorderPainted(false);
		punishmentBtn.setContentAreaFilled(false);
		punishmentBtn.setFocusPainted(false);
		punishmentBtn.setVisible(false);
		punishmentBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				punishmentBtn.setBounds(-60, 440, 600, 50);
				punishmentBtn.setIcon(punishmentButtonEnteredImage);
				punishmentBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				punishmentBtn.setBounds(-60, 440, 600, 50);
				punishmentBtn.setIcon(punishmentButtonBasicImage);
				
				punishmentBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//징벌하기 행동을 했음 
				addAction(Main.ACTION_PUNISHMENT,punishmentBtn.getIcon());
			}
		});
		
		add(punishmentBtn);
		
		fairyBtn.setBounds(-60, 490, 600, 50);
		fairyBtn.setBorderPainted(false);
		fairyBtn.setContentAreaFilled(false);
		fairyBtn.setFocusPainted(false);
		fairyBtn.setVisible(false);
		fairyBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				fairyBtn.setBounds(-60, 490, 600, 50);
				fairyBtn.setIcon(fairyButtonEnteredImage);
				fairyBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				fairyBtn.setBounds(-60, 490, 600, 50);
				fairyBtn.setIcon(fairyButtonBasicImage);
				
				fairyBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//동화보기 행동을 선택했다는 것을 체크하기 
				addAction(Main.ACTION_FAIRYSTORY,fairyBtn.getIcon());
			}
		});
		
		add(fairyBtn);
		
		trainingBtn.setBounds(-60, 540, 600, 50);
		trainingBtn.setBorderPainted(false);
		trainingBtn.setContentAreaFilled(false);
		trainingBtn.setFocusPainted(false);
		trainingBtn.setVisible(false);
		trainingBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				trainingBtn.setBounds(-60, 540, 600, 50);
				trainingBtn.setIcon(trainingButtonEnteredImage);
				trainingBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				trainingBtn.setBounds(-60, 540, 600, 50);
				trainingBtn.setIcon(trainingButtonBasicImage);
				
				trainingBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//하드 트레이닝 행동을 선택했다는 것을 체크하기 
				addAction(Main.ACTION_TRAINING,trainingBtn.getIcon());
			}
		});
		
		add(trainingBtn);
		
		endingFrankenBtn.setBounds(-60, 540, 600, 50);
		endingFrankenBtn.setBorderPainted(false);
		endingFrankenBtn.setContentAreaFilled(false);
		endingFrankenBtn.setFocusPainted(false);
		endingFrankenBtn.setVisible(false);
		endingFrankenBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				endingFrankenBtn.setBounds(-60, 540, 600, 50);
				endingFrankenBtn.setIcon(endingFrankenButtonEnteredImage);
				endingFrankenBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				endingFrankenBtn.setBounds(-60, 540, 600, 50);
				endingFrankenBtn.setIcon(endingFrankenButtonBasicImage);
				
				endingFrankenBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//프랑켄슈타인의 엔딩행동을 했다는 것을 체크함.
				addAction(Main.ENDING_ACTION_FRANKEN,endingFrankenBtn.getIcon());
			}
		});
		
		add(endingFrankenBtn);
		
		endingDraculaBtn.setBounds(-60, 540, 600, 50);
		endingDraculaBtn.setBorderPainted(false);
		endingDraculaBtn.setContentAreaFilled(false);
		endingDraculaBtn.setFocusPainted(false);
		endingDraculaBtn.setVisible(false);
		endingDraculaBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				endingDraculaBtn.setBounds(-60, 540, 600, 50);
				endingDraculaBtn.setIcon(endingDraculaButtonEnteredImage);
				endingDraculaBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				endingDraculaBtn.setBounds(-60, 540, 600, 50);
				endingDraculaBtn.setIcon(endingDraculaButtonBasicImage);
				
				endingDraculaBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//드라큘라의 엔딩행동을 선택함 
				addAction(Main.ENDING_ACTION_DRACULA,endingDraculaBtn.getIcon());
			}
		});
		
		add(endingDraculaBtn);
		
		endingZombieBtn.setBounds(-60, 540, 600, 50);
		endingZombieBtn.setBorderPainted(false);
		endingZombieBtn.setContentAreaFilled(false);
		endingZombieBtn.setFocusPainted(false);
		endingZombieBtn.setVisible(false);
		endingZombieBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				endingZombieBtn.setBounds(-60, 540, 600, 50);
				endingZombieBtn.setIcon(endingZombieButtonEnteredImage);
				endingZombieBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				endingZombieBtn.setBounds(-60, 540, 600, 50);
				endingZombieBtn.setIcon(endingZombieButtonBasicImage);
				
				endingZombieBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//좀비의 엔딩행동을 체크함
				addAction(Main.ENDING_ACTION_ZOMBIE,endingZombieBtn.getIcon());
			}
		});
		
		add(endingZombieBtn);
		
		special_doctor_btn.setBounds(-60, 300, 600, 50);
		special_doctor_btn.setBorderPainted(false);
		special_doctor_btn.setContentAreaFilled(false);
		special_doctor_btn.setFocusPainted(false);
		special_doctor_btn.setVisible(false);
		special_doctor_btn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				special_doctor_btn.setBounds(-60, 300, 600, 50);
				special_doctor_btn.setIcon(specialDoctorButtonEnteredImage);
				special_doctor_btn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				special_doctor_btn.setBounds(-60, 300, 600, 50);
				special_doctor_btn.setIcon(specialDoctorButtonBasicImage);
				
				special_doctor_btn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//의사의 특수행동을 선택함
				addAction(Main.SPECIAL_DOCTOR,special_doctor_btn.getIcon());
			}
		});
		
		add(special_doctor_btn);
		
		special_mentalist_btn.setBounds(-60, 300, 600, 50);
		special_mentalist_btn.setBorderPainted(false);
		special_mentalist_btn.setContentAreaFilled(false);
		special_mentalist_btn.setFocusPainted(false);
		special_mentalist_btn.setVisible(false);
		special_mentalist_btn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				special_mentalist_btn.setBounds(-60, 300, 600, 50);
				special_mentalist_btn.setIcon(specialPsychiatristButtonEnteredImage);
				special_mentalist_btn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				special_mentalist_btn.setBounds(-60, 300, 600, 50);
				special_mentalist_btn.setIcon(specialPsychiatristButtonBasicImage);
				
				special_mentalist_btn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//정신과의사의 특수행동을 선택함
				addAction(Main.SPECIAL_PSYCHIATRIST,special_mentalist_btn.getIcon());
			}
		});
		
		add(special_mentalist_btn);
		
		special_soldier_btn.setBounds(-60, 300, 600, 50);
		special_soldier_btn.setBorderPainted(false);
		special_soldier_btn.setContentAreaFilled(false);
		special_soldier_btn.setFocusPainted(false);
		special_soldier_btn.setVisible(false);
		special_soldier_btn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				special_soldier_btn.setBounds(-60, 300, 600, 50);
				special_soldier_btn.setIcon(specialSoldierButtonEnteredImage);
				special_soldier_btn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				special_soldier_btn.setBounds(-60, 300, 600, 50);
				special_soldier_btn.setIcon(specialSoldierButtonBasicImage);
				
				special_soldier_btn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//군인의 특수행동을 선택함
				addAction(Main.SPECIAL_SOLDIER,special_soldier_btn.getIcon());
			}
		});
		
		add(special_soldier_btn);
		
		special_farmer_btn.setBounds(-60, 300, 600, 50);
		special_farmer_btn.setBorderPainted(false);
		special_farmer_btn.setContentAreaFilled(false);
		special_farmer_btn.setFocusPainted(false);
		special_farmer_btn.setVisible(false);
		special_farmer_btn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				special_farmer_btn.setBounds(-60, 300, 600, 50);
				special_farmer_btn.setIcon(specialFarmerButtonEnteredImage);
				special_farmer_btn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				special_farmer_btn.setBounds(-60, 300, 600, 50);
				special_farmer_btn.setIcon(specialFarmerButtonBasicImage);
				
				special_farmer_btn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//농부의 특수행동을 선택함
				addAction(Main.SPECIAL_FARMER,special_farmer_btn.getIcon());
			}
		});
		
		add(special_farmer_btn);
		
		actionDoBtn.setBounds(950, 610, 100, 80);
		actionDoBtn.setBorderPainted(false);
		actionDoBtn.setContentAreaFilled(false);
		actionDoBtn.setFocusPainted(false);
		actionDoBtn.setVisible(false);
		actionDoBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				actionDoBtn.setBounds(950, 610, 100, 80);
				actionDoBtn.setIcon(actionDoButtonEnteredImage);
				actionDoBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				actionDoBtn.setBounds(950, 610, 100, 80);
				actionDoBtn.setIcon(actionDoButtonBasicImage);
				
				actionDoBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) 
			{
				back();
				actionDo();
				//행동 실행
				//gameReview(temp_now_selected_monster,temp_now_selected_job);
			}
		});
		
		add(actionDoBtn);
		
		actionCancelBtn.setBounds(1060, 610, 100, 80);
		actionCancelBtn.setBorderPainted(false);
		actionCancelBtn.setContentAreaFilled(false);
		actionCancelBtn.setFocusPainted(false);
		actionCancelBtn.setVisible(false);
		actionCancelBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				actionCancelBtn.setBounds(1060, 610, 100, 80);
				actionCancelBtn.setIcon(actionCancelButtonEnteredImage);
				actionCancelBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				actionCancelBtn.setBounds(1060, 610, 100, 80);
				actionCancelBtn.setIcon(actionCancelButtonBasicImage);
				
				actionCancelBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//행동 취소
				cancelAction();
			}
		});
		
		add(actionCancelBtn);
		
		chooseActionImage[0].setBounds(780, 330, 550, 50);
		chooseActionImage[0].setVisible(false);
	
		add(chooseActionImage[0]);
		
		chooseActionImage[1].setBounds(780, 430, 550, 50);
		chooseActionImage[1].setVisible(false);

		add(chooseActionImage[1]);
		
		chooseActionImage[2].setBounds(780, 530, 550, 50);
		chooseActionImage[2].setVisible(false);

		add(chooseActionImage[2]);
		
		statHunger.setBounds(160, 210, 200, 30);
		statHunger.setFont(new Font(null,Font.BOLD,25));
		statHunger.setVisible(false);
		statHunger.setForeground(new Color(255,255,255));
		
		add(statHunger);
		
		
		statObedience.setBounds(160, 260, 200, 30);
		statObedience.setFont(new Font(null,Font.BOLD,25));
		statObedience.setVisible(false);
		statObedience.setForeground(new Color(255,255,255));
		
		add(statObedience);
		
		statHealth.setBounds(160, 310, 200, 30);
		statHealth.setFont(new Font(null,Font.BOLD,25));
		statHealth.setVisible(false);
		statHealth.setForeground(new Color(255,255,255));
		
		add(statHealth);

		statMental.setBounds(160, 360, 200, 30);
		statMental.setFont(new Font(null,Font.BOLD,25));
		statMental.setVisible(false);
		statMental.setForeground(new Color(255,255,255));
		
		add(statMental);
		
		endingStat.setBounds(140, 560, 200, 30);
		endingStat.setFont(new Font(null,Font.BOLD,25));
		endingStat.setVisible(false);
		endingStat.setForeground(new Color(255,255,255));
		
		add(endingStat);
		
		statDay.setBounds(160,410,200,30);
		statDay.setFont(new Font(null,Font.BOLD,25));
		statDay.setVisible(false);
		statDay.setForeground(new Color(255,255,255));
		
		add(statDay);
		
		ending_text.setBounds(160,200,900,30);
		ending_text.setFont(new Font(null,Font.BOLD,25));
		ending_text.setVisible(false);
		ending_text.setForeground(new Color(255,255,255));
		
		add (ending_text);
		
		backBtn.setBounds(30, 30, 64, 64);
		backBtn.setBorderPainted(false);
		backBtn.setContentAreaFilled(false);
		backBtn.setFocusPainted(false);
		backBtn.setVisible(false);
		backBtn.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				backBtn.setBounds(30, 30, 64, 64);
				backBtn.setIcon(backButtonEnteredImage);
				backBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("clicked.mp3",false);
				buttonEnteredMusic.start();
			}
			public void mouseExited(MouseEvent e) {
				backBtn.setBounds(30, 30, 64, 64);
				backBtn.setIcon(backButtonBasicImage);
				
				backBtn.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			public void mousePressed(MouseEvent e) {
				//뒤로 가기
				back();
			}
		});
		
		add(backBtn);
		
		menuBar.setBounds(0, 0, 1280, 32);
		menuBar.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				mouseX = e.getX();
				mouseY = e.getY();
			}
		});
		
		menuBar.addMouseMotionListener(new MouseMotionAdapter() {
			public void mouseDragged(MouseEvent e) {
				int x = e.getXOnScreen();
				int y= e.getYOnScreen();
				setLocation(x - mouseX, y- mouseY);
			}
		});

		add(menuBar);

	}
	
	public void paint(Graphics g) {
		screenImage = createImage(Main.SCREEN_WIDTH,Main.SCREEN_HEIGHT);
		screenGraphic = screenImage.getGraphics();
		screenDraw(screenGraphic);
		g.drawImage(screenImage, 0, 0, null);
	}
	
	public void screenDraw(Graphics g) {
		g.drawImage(background, 0, 0, null);
		if(isMainScreen) {
			g.drawImage(selectedMonsterImage, 200, 90, null);
			g.drawImage(selectedJobImage, 700, 90, null);
		}//이미지만 사용
		if(isGameScreen) {
			if(nowSelectedMonster == Main.CHOOSE_ZOOMBIE && monsterList.get(nowSelectedMonster).getEndingCondition()==5) {
				background =  new ImageIcon(Main.class.getResource("../images/zombieHalfImage.png")).getImage();
				monsterImage = new ImageIcon(Main.class.getResource("../images/zombiePhase1.png")).getImage();
			}
			else
			{
				background =  new ImageIcon(Main.class.getResource("../images/"+monsterList.get(nowSelectedMonster).getGameImage())).getImage();
				monsterImage = new ImageIcon(Main.class.getResource("../images/"+monsterList.get(nowSelectedMonster).getMonsterSelectedImage())).getImage();
			}
		
			g.drawImage(monsterImage, 460, 70, null);
			
		}
		if(isActionShow) {
			g.drawImage(actionBar, -60, 70, null);
			g.drawImage(actionMenuBar, 760, 150, null);
		}
		if(isStatShow) {
			g.drawImage(statBar, -60, 90, null);
		}
		if(isSpecialActionShow) {
			g.drawImage(actionMenuBar, 760, 150, null);
		}
		if(isGameOver) {
			if(nowSelectedMonster == Main.CHOOSE_FRANKEN) {
				g.drawImage(goodEndingFranken, 0, 0,null);
			}
			if(nowSelectedMonster == Main.CHOOSE_DRACULA) {
				g.drawImage(goodEndingDracula, 0, 0,null);
			}
			if(nowSelectedMonster == Main.CHOOSE_ZOOMBIE) {
				g.drawImage(goodEndingZombie, 0, 0,null);
			}
		}
		paintComponents(g);//add에서
		this.repaint();
	}
	public void selectedMonster(int nowSelectedMonster) {

		selectedMonsterImage = new ImageIcon(Main.class.getResource("../images/" + monsterList.get(nowSelectedMonster).getMonsterChooseImage())).getImage();		
	}
	
	public void selectedJob(int nowSelectedJob) {

		selectedJobImage = new ImageIcon(Main.class.getResource("../images/" + jobList.get(nowSelectedJob).getJobImage())).getImage();
	}
	
	public void selectMonsterLeft() {//몬스터 왼쪽 버튼
		if(nowSelectedMonster==0){
			nowSelectedMonster = monsterList.size()-1;
		}
		else
			nowSelectedMonster--;
		selectedMonster(nowSelectedMonster);
	}
	
	public void selectMonsterRight() {//몬스터 오른쪽 버튼 누르기
		if(nowSelectedMonster==monsterList.size()-1){
			nowSelectedMonster = 0;
		}
		else
			nowSelectedMonster++;
		selectedMonster(nowSelectedMonster);
	}
	
	public void selectJobLeft() {//몬스터 왼쪽 버튼
		if(nowSelectedJob==0){
			nowSelectedJob = jobList.size()-1;
		}
		else
			nowSelectedJob--;
		selectedJob(nowSelectedJob);
	}
	public void selectJobRight() {//몬스터 오른쪽 버튼 누르기
		if(nowSelectedJob==jobList.size()-1){
			nowSelectedJob = 0;
		}
		else
			nowSelectedJob++;
		selectedJob(nowSelectedJob);
	}
	public void gameStart(int nowSelectedMonster, int nowSelectedJob) {
		
		init(nowSelectedMonster, nowSelectedJob);
		
		isMainScreen = false;
		jobLeftBtn.setVisible(false);
		jobRightBtn.setVisible(false);
		monsterLeftBtn.setVisible(false);
		monsterRightBtn.setVisible(false);
		nextBtn.setVisible(false);
		actionBtn.setVisible(true);
		statBtn.setVisible(true);
		specialBtn.setVisible(true);
		saveBtn.setVisible(true);
		
		
		isGameScreen = true;
		selectedMusic = new Music(monsterList.get(nowSelectedMonster).getGameMusic(),true);
		selectedMusic.start();
	}
public void gameLoad(int nowSelectedMonster, int nowSelectedJob) {
		
		//init(nowSelectedMonster, nowSelectedJob);
		
		isMainScreen = false;
		jobLeftBtn.setVisible(false);
		jobRightBtn.setVisible(false);
		monsterLeftBtn.setVisible(false);
		monsterRightBtn.setVisible(false);
		startBtn.setVisible(false);
		lodingBtn.setVisible(false);
		quitBtn.setVisible(false);
		
		nextBtn.setVisible(false);
		if(nowSelectedMonster == Main.CHOOSE_ZOOMBIE && monsterList.get(nowSelectedMonster).getEndingCondition()==5) {
			background =  new ImageIcon(Main.class.getResource("../images/zombieHalfImage.png")).getImage();
			monsterImage = new ImageIcon(Main.class.getResource("../images/zombiePhase1.png")).getImage();
		}
		else
		{
			background =  new ImageIcon(Main.class.getResource("../images/"+monsterList.get(nowSelectedMonster).getGameImage())).getImage();
			monsterImage = new ImageIcon(Main.class.getResource("../images/"+monsterList.get(nowSelectedMonster).getMonsterSelectedImage())).getImage();
		}
		actionBtn.setVisible(true);
		statBtn.setVisible(true);
		specialBtn.setVisible(true);
		saveBtn.setVisible(true);
		
		
		isGameScreen = true;
		selectedMusic = new Music(monsterList.get(nowSelectedMonster).getGameMusic(),true);
		selectedMusic.start();
	}

	public void enterMain() {

		startBtn.setVisible(false);
		quitBtn.setVisible(false);
		lodingBtn.setVisible(false);
		background = new ImageIcon(Main.class.getResource("../images/gameBackground1.png")).getImage();
		monsterLeftBtn.setVisible(true);
		monsterRightBtn.setVisible(true);
		jobLeftBtn.setVisible(true);
		jobRightBtn.setVisible(true);
		nextBtn.setVisible(true);
		isMainScreen = true;
		selectedMonster(0);
		selectedJob(0);
	}
	public void ActionListShow() {
		statBtn.setVisible(false);
		saveBtn.setVisible(false);
		actionBtn.setVisible(false);
		specialBtn.setVisible(false);
		backBtn.setVisible(true);
		
		feedBtn.setVisible(true);
		caneBtn.setVisible(true);
		patBtn.setVisible(true);
		shotBtn.setVisible(true);
		
		feedTrushBtn.setVisible(true);
		punishmentBtn.setVisible(true);
		fairyBtn.setVisible(true);
		trainingBtn.setVisible(true);
		
		actionDoBtn.setVisible(true);	
		actionCancelBtn.setVisible(true);
		

		chooseActionImage[0].setVisible(true);
		chooseActionImage[1].setVisible(true);
		chooseActionImage[2].setVisible(true);
		
		isActionShow = true;
	}
	public void specialActionListShow() {
		
		statBtn.setVisible(false);
		saveBtn.setVisible(false);
		actionBtn.setVisible(false);
		specialBtn.setVisible(false);
		backBtn.setVisible(true);
		
		actionDoBtn.setVisible(true);	
		actionCancelBtn.setVisible(true);
		

		chooseActionImage[0].setVisible(true);
		chooseActionImage[1].setVisible(true);
		chooseActionImage[2].setVisible(true);
		
		if(temp_now_selected_monster == Main.CHOOSE_FRANKEN) {
			endingFrankenBtn.setVisible(true);
		}
		else if(temp_now_selected_monster == Main.CHOOSE_DRACULA) {
			endingDraculaBtn.setVisible(true);		
		}
		else if(temp_now_selected_monster == Main.CHOOSE_ZOOMBIE) {
			endingZombieBtn.setVisible(true);
		}
		switch(temp_now_selected_job) 
		{
		case Main.CHOOSE_DOCTOR:
			special_doctor_btn.setVisible(true);
			break;
		case Main.CHOOSE_PSYCHOLOGIST:
			special_mentalist_btn.setVisible(true);
			break;
		case Main.CHOOSE_SOLDIER:
			special_soldier_btn.setVisible(true);
			break;
		case Main.CHOOSE_FARMER:
			special_farmer_btn.setVisible(true);
			break;
		}
		isSpecialActionShow = true;
	}
	public void back() {
		statBtn.setVisible(true);
		saveBtn.setVisible(true);
		specialBtn.setVisible(true);
		actionBtn.setVisible(true);
		backBtn.setVisible(false);
		
		feedBtn.setVisible(false);
		caneBtn.setVisible(false);
		patBtn.setVisible(false);
		shotBtn.setVisible(false);
		
		feedTrushBtn.setVisible(false);
		punishmentBtn.setVisible(false);
		fairyBtn.setVisible(false);
		trainingBtn.setVisible(false);
		actionDoBtn.setVisible(false);
		actionCancelBtn.setVisible(false);
		
		chooseActionImage[0].setVisible(false);
		chooseActionImage[1].setVisible(false);
		chooseActionImage[2].setVisible(false);
		
		endingFrankenBtn.setVisible(false);
		endingDraculaBtn.setVisible(false);
		endingZombieBtn.setVisible(false);
		
		special_doctor_btn.setVisible(false);
		special_soldier_btn.setVisible(false);
		special_farmer_btn.setVisible(false);
		special_mentalist_btn.setVisible(false);
		
		
		statHunger.setVisible(false);
		statObedience.setVisible(false);
		statHealth.setVisible(false);
		statMental.setVisible(false);
		endingStat.setVisible(false);
		statDay.setVisible(false);
		
		isActionShow = false;
		isStatShow =false;
		isSpecialActionShow = false;
	}
	public void StatListShow() {

		statBtn.setVisible(false);
		saveBtn.setVisible(false);
		actionBtn.setVisible(false);
		specialBtn.setVisible(false);
		backBtn.setVisible(true);
		
		statHunger.setVisible(true);
		statObedience.setVisible(true);
		statHealth.setVisible(true);
		statMental.setVisible(true);
		endingStat.setVisible(true);
		statDay.setVisible(true);
		isStatShow =true;
	}
	public void GameOver()
	{
		
		statBtn.setVisible(false);
		saveBtn.setVisible(false);
		actionBtn.setVisible(false);
		specialBtn.setVisible(false);
		
		ending_text.setVisible(true);
		quitBtn.setVisible(true);
		//startBtn.setVisible(true);
		isGameOver = true;
		isGameScreen = false;
	}
	public void addAction(int action,Icon icon) {
		
		//엔딩행동
		if(action >= Main.ENDING_ACTION_FRANKEN) {//선택한 행동이 엔딩행동이면
			if(actionIndex ==-1) {//아무행동도 선택하지 않았으면
					ending_flag= 1;
					chooseActionImage[++actionIndex].setIcon(icon);
					actionList[actionIndex] = action;
					chooseActionImage[++actionIndex].setIcon(icon);
					actionList[actionIndex] = action;
					chooseActionImage[++actionIndex].setIcon(icon);
					actionList[actionIndex] = action;
					action_list[0] = maingame.ending;
			}
			else
			{
				JOptionPane.showMessageDialog(this, "엔딩행동을 하면 다른 행동을 할 수 없습니다.");
			}
		}
		//전직별 특수행동
		if(action>=Main.SPECIAL_DOCTOR && action<=Main.SPECIAL_PSYCHIATRIST)
		{
			if(actionIndex ==-1) {//아무행동도 선택하지 않았으면
				ending_flag= 2;
				chooseActionImage[++actionIndex].setIcon(icon);
				actionList[actionIndex] = action;
				chooseActionImage[++actionIndex].setIcon(icon);
				actionList[actionIndex] = action;
				chooseActionImage[++actionIndex].setIcon(icon);
				actionList[actionIndex] = action;
				action_list[0] = action+1;
			}
			else
			{
				JOptionPane.showMessageDialog(this, "특수행동을 하면 다른 행동을 할 수 없습니다.");
			}
				
		}
		//일반 행동이면
		if(action <= Main.ACTION_TRAINING) {
			if(actionIndex<2) {
				chooseActionImage[++actionIndex].setIcon(icon);
				actionList[actionIndex] = action;
				action_list[actionIndex] = action+1;
			}
			else {
				JOptionPane.showMessageDialog(this, "더이상 추가할 수 없습니다.");
			}
		}
		
	}
	public void cancelAction() {
		if(actionIndex <0) {
				JOptionPane.showMessageDialog(this, "더이상 취소할 행동이 없습니다.");
		}
		else {
			if(actionList[actionIndex] < Main.SPECIAL_DOCTOR) {
				chooseActionImage[actionIndex--].setIcon(undeterminedImage);
				
			}
			else {
				chooseActionImage[actionIndex--].setIcon(undeterminedImage);
				
				chooseActionImage[actionIndex--].setIcon(undeterminedImage);
				
				chooseActionImage[actionIndex--].setIcon(undeterminedImage);
				
			}
		}
	}
	int temp_now_selected_monster,temp_now_selected_job;//sumin
	public void init(int nowSelectedMonster, int nowSelectedJob) {
		int monster = 0,job = 0;
		temp_now_selected_monster = nowSelectedMonster;
		temp_now_selected_job = nowSelectedJob;
		if(nowSelectedMonster == Main.CHOOSE_FRANKEN) {
			monster = maingame.pranc;//sumin
			monsterList.get(nowSelectedMonster).initHealth(maingame.first_pranc_health);
			monsterList.get(nowSelectedMonster).initHunger(maingame.first_pranc_hunger);
			monsterList.get(nowSelectedMonster).initMental(maingame.first_pranc_mental);
			monsterList.get(nowSelectedMonster).initObedience(maingame.first_pranc_obedience);
		}
		else if(nowSelectedMonster == Main.CHOOSE_DRACULA) {
			monster = maingame.vamp;//sumin
			monsterList.get(nowSelectedMonster).initHealth(maingame.first_vamp_health);
			monsterList.get(nowSelectedMonster).initHunger(maingame.first_vamp_hunger);
			monsterList.get(nowSelectedMonster).initMental(maingame.first_vamp_mental);
			monsterList.get(nowSelectedMonster).initObedience(maingame.first_vamp_obedience);
		}
		else if(nowSelectedMonster == Main.CHOOSE_ZOOMBIE) {
			monster = maingame.zombie;//sumin
			monsterList.get(nowSelectedMonster).initHealth(maingame.first_zombie_health);
			monsterList.get(nowSelectedMonster).initHunger(maingame.first_zombie_hunger);
			monsterList.get(nowSelectedMonster).initMental(maingame.first_zombie_mental);
			monsterList.get(nowSelectedMonster).initObedience(maingame.first_zombie_obedience);
		}
		//sumin
		switch(nowSelectedJob)
		{
		case Main.CHOOSE_DOCTOR:
			job = maingame.doctor;
			break;
		case Main.CHOOSE_FARMER:
			job = maingame.farmer;
			break;
		case Main.CHOOSE_SOLDIER:
			job = maingame.soldier;
			break;
		case Main.CHOOSE_PSYCHOLOGIST:
			job = maingame.mentalist;
			break;
		}
		
		game_stat = game_data.init_my_creature_job(monster, job);
		//sumin
		/*statHunger.setText("   허기: "+monsterList.get(nowSelectedMonster).getHunger());
		statObedience.setText(" 복종도: "+monsterList.get(nowSelectedMonster).getObedience());
		statHealth.setText("   건강: "+monsterList.get(nowSelectedMonster).getHealth());
		statMental.setText("정신 건강: "+monsterList.get(nowSelectedMonster).getMental());
		endingStat.setText("현재 단계: "+monsterList.get(nowSelectedMonster).getEndingCondition()+" 단계");*/
		statHunger.setText("   허기: "+game_stat.hunger);
		statObedience.setText(" 복종도: "+game_stat.obedience);
		statHealth.setText("   건강: "+game_stat.health);
		statMental.setText("정신 건강: "+game_stat.mental);
		endingStat.setText("현재 단계: "+game_stat.ending_step+" 단계");
		statDay.setText("지난날 :" + game_stat.day +"일");
		
	}
	public void game_save()
	{
		
		try {
			File file = new File("../sav.txt");
			BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(file));
			if(file.isFile()&& file.canWrite())
			{
				bufferedWriter.write(""+temp_now_selected_monster);
				System.out.println(temp_now_selected_monster);
				bufferedWriter.newLine();
				bufferedWriter.write(""+temp_now_selected_job);
				System.out.println(temp_now_selected_job);
				bufferedWriter.newLine();
				bufferedWriter.write(""+game_stat.hunger);
				System.out.println(game_stat.hunger);
				bufferedWriter.newLine();
				bufferedWriter.write(""+game_stat.health);
				System.out.println(game_stat.health);
				bufferedWriter.newLine();
				bufferedWriter.write(""+game_stat.obedience);
				System.out.println(game_stat.obedience);
				bufferedWriter.newLine();
				bufferedWriter.write(""+game_stat.mental);
				System.out.println(game_stat.mental);
				bufferedWriter.newLine();
				bufferedWriter.write(""+game_stat.day);
				bufferedWriter.newLine();
				bufferedWriter.write(""+game_stat.ending_step);
				bufferedWriter.newLine();
				bufferedWriter.close();
			}
		
		
		
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
	}
	public void game_load()
	{
		int []stat = new int [8];
		int i=0;
		int monster,job,hunger,health,obedience,mental,day,ending;
		try {
			File file = new File("../sav.txt");
			FileReader reader = new FileReader(file);
			BufferedReader bufreader = new BufferedReader(reader);
			String line = "";
			
			while((line =bufreader.readLine())!=null)
			{
				stat[i] = atoi(line);
				i++;
			}
			/*for(i=0;i<8;i++)
			{
				System.out.printf("%d\n", stat[i]);
			}*///배열로 잘갖고오긴함
			temp_now_selected_monster = stat[0];
			nowSelectedMonster = stat[0];
			nowSelectedJob = stat[1];
			temp_now_selected_job = stat[1];
			load(stat);
			bufreader.close();
		
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
	}
	public void load(int []stat)
	{

		game_stat=game_data.load_my_creature(stat[0],stat[1],stat[2],stat[3],stat[4],stat[5],stat[6],stat[7]);
		statHunger.setText("   허기: "+game_stat.hunger);
		statObedience.setText(" 복종도: "+game_stat.obedience);
		statHealth.setText("   건강: "+game_stat.health);
		statMental.setText("정신 건강: "+game_stat.mental);
		endingStat.setText("현재 단계: "+game_stat.ending_step+" 단계");
		statDay.setText("지난날 :" + game_stat.day +"일");
		monsterList.get(stat[0]).setEndingCondition(game_stat.ending_step);//not completed
		monsterList.get(stat[0]).initHealth(game_stat.health);
		monsterList.get(stat[0]).initHunger(game_stat.hunger);
		monsterList.get(stat[0]).initMental(game_stat.mental);
		monsterList.get(stat[0]).initObedience(game_stat.obedience);
	}
	public int atoi(String str)
	{
		int radix =10;
		int result = 0;
		byte[]temp = str.getBytes();
		for(int i=0;i<temp.length;i++)
		{
			result = (result*radix) + temp[i]-'0';
		}
		return result;
	}
	public void actionDo() {
		if(actionIndex !=2)
		{
			JOptionPane.showMessageDialog(this, "3가지의 행동을 선택해 주세요.");
			return;
		}
		if(ending_flag ==2 && game_data.cool_check() == false)//특수행동인데, 쿨타임이 지나지 않았다면
		{
			ending_flag = 0;
			cancelAction();
			JOptionPane.showMessageDialog(this, "특수행동의 쿨타임이 지나지 않았습니다.");
			return;
		}
		//day = 30;//test
		game_stat = game_data.game_play(action_list, ending_flag, day);
		//System.out.printf("%d\n",ending_flag);
		
		day = game_stat.day;
		
		if(game_stat.ending_flag != maingame.still_ok) //이때 스탯 -일수도 있음
		{
			ending_text.setText(game_stat.text);
			//이때 엔딩화면 표시하면 됨 엔딩텍스트에 엔딩텍스트 담겨있음
			GameOver();
			return;//not completed
			//이때 엔딩 화면 표시해야함
		}
		statHunger.setText("   허기: "+ game_stat.hunger);
		statObedience.setText(" 복종도: "+game_stat.obedience);
		statHealth.setText("   건강: "+game_stat.health);
		statMental.setText("정신 건강: "+game_stat.mental);
		endingStat.setText("현재 단계: "+game_stat.ending_step + "단계");
		statDay.setText("지난날 : " + game_stat.day +"일");
	
		//혹시 몰라서 몬스터 리스트도 변경
		monsterList.get(temp_now_selected_monster).setEndingCondition(game_stat.ending_step);//not completed
		monsterList.get(temp_now_selected_monster).setHealth(game_stat.health);
		monsterList.get(temp_now_selected_monster).setHunger(game_stat.hunger);
		monsterList.get(temp_now_selected_monster).setMental(game_stat.mental);
		monsterList.get(temp_now_selected_monster).setObedience(game_stat.obedience);
		
		int num=1;
		if(0==ending_flag) num =3;
		if(1==ending_flag || ending_flag ==2) num =1;
		ending_flag = 0;
		for(int i=0;i<num;i++)
		{
			cancelAction();
		}
		if(game_data.event_check() == true)
		{
	
			event_view = game_data.event_occur();
			int ans = JOptionPane.showConfirmDialog(null, event_view.Text,event_view.Title, JOptionPane.YES_NO_OPTION, JOptionPane.PLAIN_MESSAGE);
			//이때만 이벤트 발생함
			game_event = game_data.event_choice(ans, event_view.index);
			JOptionPane.showMessageDialog(null, game_event.text, "결과", JOptionPane.INFORMATION_MESSAGE);
		
			statHunger.setText("   허기: "+ game_event.hunger);
			statObedience.setText(" 복종도: "+game_event.obedience);
			statHealth.setText("   건강: "+game_event.health);
			statMental.setText("정신 건강: "+game_event.mental);

		
			//혹시 몰라서 몬스터 리스트도 변경
			monsterList.get(temp_now_selected_monster).setEndingCondition(game_stat.ending_step);
			monsterList.get(temp_now_selected_monster).setHealth(game_event.health);
			monsterList.get(temp_now_selected_monster).setHunger(game_event.hunger);
			monsterList.get(temp_now_selected_monster).setMental(game_event.mental);
			monsterList.get(temp_now_selected_monster).setObedience(game_event.obedience);
		
		
		}
	}
}
