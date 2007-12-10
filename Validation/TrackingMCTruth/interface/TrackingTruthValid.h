#ifndef TrackingTruthValid_h
#define TrackingTruthValid_h

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Daemon/interface/MonitorDaemon.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/ParameterSet/interface/InputTag.h"

#include <iostream>
#include <string>
#include <TH1F.h>
#include <TH2F.h>

class TrackingTruthValid  : public edm::EDAnalyzer {
 public:
  //Constructor
  explicit TrackingTruthValid(const edm::ParameterSet& conf) ;
  //Destructor
  ~TrackingTruthValid(){} ;
  
  virtual void analyze(const edm::Event&, const edm::EventSetup& );

  void beginJob(const edm::ParameterSet& conf);
  void endJob();
  
 private:
  DaqMonitorBEInterface* dbe_;
  edm::ParameterSet conf_;
  std::string outputFile;
  edm::InputTag src_;
  
  MonitorElement* meTPMass;
  MonitorElement* meTPCharge; 
  MonitorElement* meTPId;
  MonitorElement* meTPAllHits;
  MonitorElement* meTPMatchedHits;
  MonitorElement* meTPPt;
  MonitorElement* meTPEta;
  MonitorElement* meTPPhi;
  MonitorElement* meTPVtxX;
  MonitorElement* meTPVtxY;
  MonitorElement* meTPVtxZ; 
  MonitorElement* meTPtip;
  MonitorElement* meTPlip;
  
};

#endif
