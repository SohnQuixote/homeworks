package level3;

public class Job {

	private String JobImage;
	
	
	public String getJobImage() {
		return JobImage;
	}
	public void setJobImage(String startImage) {
		this.JobImage = startImage;
	}
	public Job(String jobImage) {
		super();
		JobImage = jobImage;
	}

}
