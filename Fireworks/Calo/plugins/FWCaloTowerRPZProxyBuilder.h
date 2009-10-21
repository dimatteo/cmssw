// -*- C++ -*-
// $Id: FWCaloTowerRPZProxyBuilder.h,v 1.2 2009/01/23 21:35:40 amraktad Exp $
//

#ifndef Fireworks_Calo_CaloTowerProxyRPZBuilder_h
#define Fireworks_Calo_CaloTowerProxyRPZBuilder_h

class TH2F;
class TEveCaloDataHist;

#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"
#include "Fireworks/Core/interface/FWRPZDataProxyBuilder.h"

class FWCaloTowerRPZProxyBuilderBase : public FWRPZDataProxyBuilder
{
public:
   FWCaloTowerRPZProxyBuilderBase(bool handleEcal, const char* name);
   virtual ~FWCaloTowerRPZProxyBuilderBase();

protected:
   void itemBeingDestroyedImp(const FWEventItem*);

   const CaloTowerCollection* m_towers;

private:
   virtual void build(const FWEventItem* iItem, TEveElementList** product);

   virtual void modelChanges(const FWModelIds& iIds,
                             TEveElement* iElements );
   virtual void applyChangesToAllModels(TEveElement* iElements);

   FWCaloTowerRPZProxyBuilderBase(const FWCaloTowerRPZProxyBuilderBase&); // stop default
   const FWCaloTowerRPZProxyBuilderBase& operator=(const FWCaloTowerRPZProxyBuilderBase&); // stop default

   // ---------- member data --------------------------------
   static TEveCaloDataHist* m_data;
   Bool_t m_ownData;

   bool         m_handleEcal;
   const char*  m_histName;
   TH2F*        m_hist;
   Int_t        m_sliceIndex;
};

//
// ECal
//

class FWECalCaloTowerRPZProxyBuilder : public FWCaloTowerRPZProxyBuilderBase
{
public:
   FWECalCaloTowerRPZProxyBuilder(): FWCaloTowerRPZProxyBuilderBase(true, "ecal3D") {}
   virtual ~FWECalCaloTowerRPZProxyBuilder() {}

   // ---------- member functions ---------------------------
   REGISTER_PROXYBUILDER_METHODS();

private:
   FWECalCaloTowerRPZProxyBuilder(const FWECalCaloTowerRPZProxyBuilder&); // stop default

   const FWECalCaloTowerRPZProxyBuilder& operator=(const FWECalCaloTowerRPZProxyBuilder&); // stop default
};

//
// HCal
//

class FWHCalCaloTowerRPZProxyBuilder : public FWCaloTowerRPZProxyBuilderBase
{
public:
   FWHCalCaloTowerRPZProxyBuilder() : FWCaloTowerRPZProxyBuilderBase(false, "hcal3D") {}
   virtual ~FWHCalCaloTowerRPZProxyBuilder() {}

   // ---------- member functions ---------------------------
   REGISTER_PROXYBUILDER_METHODS();

private:
   FWHCalCaloTowerRPZProxyBuilder(const FWHCalCaloTowerRPZProxyBuilder&); // stop default

   const FWHCalCaloTowerRPZProxyBuilder& operator=(const FWHCalCaloTowerRPZProxyBuilder&); // stop default
};



#endif
