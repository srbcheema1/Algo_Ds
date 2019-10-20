FRAME_SIZE=10       //Number of data points you take into consideration
MUL_FACTOR=0.005    //Amount of fine tuning you require. Smaller the factor, more is the sensitivity

def compute_bounds(history_data,frame_size,factor):
    if len(history_data)<frame_size :
        return None

    if len(history_data)>frame_size :
        del history_data[0:len(history_data)-frame_size]   //To remove the data points apart from the last 10 points
    Mn=statistics.mean(history_data)                                 
    Variance=0
    for data in history_data :
        Variance += math.pow((data-Mn),2)
    Zn = factor * math.sqrt(Variance / frame_size)                  //Process to compute dynamic thresholds
    High_bound = history_data[frame_size-1]+Zn
    Low_bound = history_data[frame_size-1]-Zn
    return [High_bound,Low_bound]

history_data=[]

while True:
   
	value=input("Enter Data")
    print ("This is the value "+value)
    sensor_value=0
  
        sensor_value = int(value)

	bound = compute_bounds(history_data,FRAME_SIZE,MUL_FACTOR)
    if not bound:
        required_data_count=conf.FRAME_SIZE-len(history_data)
        print("Not enough data to compute Z-score. Need ",required_data_count," more data points")   //If data points aren't enough
        history_data.append(value)
        continue

        if sensor_value > bound[0] :
            print ("The value increased suddenly")                //Response, in case of anomaly     
   
        elif sensor_value < bound[1]:
            print ("The value decreased suddenly")
        
        history_data.append(sensor_value)
   
