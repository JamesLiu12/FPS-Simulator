
#ifndef FPS_SIMULATOR_RUNNER_H
#define FPS_SIMULATOR_RUNNER_H

struct Runner{
    double frame_rate;
    //struct Scene scene;
    
};

void Runner_Run(struct Runner *runner);
void Runner_Init(struct Runner *runner);
void Runner_Load(struct Runner *runner);
#endif //FPS_SIMULATOR_RUNNER_H
