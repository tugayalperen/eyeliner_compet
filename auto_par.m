arr = [1,2,3,4,5];


for i = length(arr):-1:1
    simIn(i) = Simulink.SimulationInput('parrotMinidroneCompetition');
    simIn(i) = simIn(i).setVariable('varvar',arr(i));
end
% 
% 
% 
% simIn = Simulink.SimulationInput('parrotMinidroneCompetition');
% simIn = simIn.setVariable('varvar',arr(1));
% out = sim(simIn)

out = parsim(simIn)