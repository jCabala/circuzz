#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
#include "fr.hpp"
void NOT_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void NOT_0_run(uint ctx_index,Circom_CalcWit* ctx);
void OR_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void OR_1_run(uint ctx_index,Circom_CalcWit* ctx);
void AND_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void AND_2_run(uint ctx_index,Circom_CalcWit* ctx);
void IsZero_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsZero_3_run(uint ctx_index,Circom_CalcWit* ctx);
void IsEqual_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsEqual_4_run(uint ctx_index,Circom_CalcWit* ctx);
void Num2Bits_5_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Num2Bits_5_run(uint ctx_index,Circom_CalcWit* ctx);
void LessThan_6_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void LessThan_6_run(uint ctx_index,Circom_CalcWit* ctx);
void GreaterEqThan_7_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void GreaterEqThan_7_run(uint ctx_index,Circom_CalcWit* ctx);
void MultiMux1_8_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiMux1_8_run(uint ctx_index,Circom_CalcWit* ctx);
void Mux1_9_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Mux1_9_run(uint ctx_index,Circom_CalcWit* ctx);
void GreaterThan_10_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void GreaterThan_10_run(uint ctx_index,Circom_CalcWit* ctx);
void main_template_11_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void main_template_11_run(uint ctx_index,Circom_CalcWit* ctx);
Circom_TemplateFunction _functionTable[12] = { 
NOT_0_run,
OR_1_run,
AND_2_run,
IsZero_3_run,
IsEqual_4_run,
Num2Bits_5_run,
LessThan_6_run,
GreaterEqThan_7_run,
MultiMux1_8_run,
Mux1_9_run,
GreaterThan_10_run,
main_template_11_run };
Circom_TemplateFunction _functionTableParallel[12] = { 
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL };
uint get_main_input_signal_start() {return 2;}

uint get_main_input_signal_no() {return 0;}

uint get_total_signal_no() {return 2312;}

uint get_number_of_components() {return 86;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 2312;}

uint get_size_of_constants() {return 17;}

uint get_size_of_io_map() {return 0;}

uint get_size_of_bus_field_map() {return 0;}

void release_memory_component(Circom_CalcWit* ctx, uint pos) {{

if (pos != 0){{

if(ctx->componentMemory[pos].subcomponents)
delete []ctx->componentMemory[pos].subcomponents;

if(ctx->componentMemory[pos].subcomponentsParallel)
delete []ctx->componentMemory[pos].subcomponentsParallel;

if(ctx->componentMemory[pos].outputIsSet)
delete []ctx->componentMemory[pos].outputIsSet;

if(ctx->componentMemory[pos].mutexes)
delete []ctx->componentMemory[pos].mutexes;

if(ctx->componentMemory[pos].cvs)
delete []ctx->componentMemory[pos].cvs;

if(ctx->componentMemory[pos].sbct)
delete []ctx->componentMemory[pos].sbct;

}}


}}


// function declarations
// template declarations
void NOT_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "NOT";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void NOT_0_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[4];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
signalValues[mySignalStart + 0] = Fr_sub(Fr_add(1ull,signalValues[mySignalStart + 1]),Fr_mul(2ull,signalValues[mySignalStart + 1]));
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void OR_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 1;
ctx->componentMemory[coffset].templateName = "OR";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void OR_1_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[3];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
signalValues[mySignalStart + 0] = Fr_sub(Fr_add(signalValues[mySignalStart + 1],signalValues[mySignalStart + 2]),Fr_mul(signalValues[mySignalStart + 1],signalValues[mySignalStart + 2]));
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void AND_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 2;
ctx->componentMemory[coffset].templateName = "AND";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void AND_2_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[1];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
signalValues[mySignalStart + 0] = Fr_mul(signalValues[mySignalStart + 1],signalValues[mySignalStart + 2]);
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void IsZero_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 3;
ctx->componentMemory[coffset].templateName = "IsZero";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void IsZero_3_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[3];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
if(Fr_isTrue(Fr_neq(signalValues[mySignalStart + 1],0ull))){
// load src
// end load src
signalValues[mySignalStart + 2] = Fr_div(1ull,signalValues[mySignalStart + 1]);
}else{
// load src
// end load src
signalValues[mySignalStart + 2] = 0ull;
}
// load src
// end load src
signalValues[mySignalStart + 0] = Fr_add(Fr_mul(Fr_neg(signalValues[mySignalStart + 1]),signalValues[mySignalStart + 2]),1ull);
{
if (!Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + 1],signalValues[mySignalStart + 0]),0ull))) std::cout << "Failed assert in template/function " << myTemplateName << " line 33. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + 1],signalValues[mySignalStart + 0]),0ull)));
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void IsEqual_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 4;
ctx->componentMemory[coffset].templateName = "IsEqual";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void IsEqual_4_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[1];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
std::string new_cmp_name = "isz";
IsZero_3_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = Fr_sub(signalValues[mySignalStart + 2],signalValues[mySignalStart + 1]);
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsZero_3_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
signalValues[mySignalStart + 0] = ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0];
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void Num2Bits_5_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 5;
ctx->componentMemory[coffset].templateName = "Num2Bits";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void Num2Bits_5_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[4];
u64 lvar[4];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
lvar[0] = 253ull;
// load src
// end load src
lvar[1] = 0ull;
// load src
// end load src
lvar[2] = 1ull;
// load src
// end load src
lvar[3] = 0ull;
while(Fr_isTrue(Fr_lt(lvar[3],253ull))){
// load src
// end load src
signalValues[mySignalStart + ((1 * Fr_toInt(lvar[3])) + 0)] = Fr_band(Fr_shr(signalValues[mySignalStart + 253],lvar[3]),1ull);
{
if (!Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + ((1 * Fr_toInt(lvar[3])) + 0)],Fr_sub(signalValues[mySignalStart + ((1 * Fr_toInt(lvar[3])) + 0)],1ull)),0ull))) std::cout << "Failed assert in template/function " << myTemplateName << " line 33. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + ((1 * Fr_toInt(lvar[3])) + 0)],Fr_sub(signalValues[mySignalStart + ((1 * Fr_toInt(lvar[3])) + 0)],1ull)),0ull)));
}
// load src
// end load src
lvar[1] = Fr_add(lvar[1],Fr_mul(signalValues[mySignalStart + ((1 * Fr_toInt(lvar[3])) + 0)],lvar[2]));
// load src
// end load src
lvar[2] = Fr_add(lvar[2],lvar[2]);
// load src
// end load src
lvar[3] = Fr_add(lvar[3],1ull);
}
{
if (!Fr_isTrue(Fr_eq(lvar[1],signalValues[mySignalStart + 253]))) std::cout << "Failed assert in template/function " << myTemplateName << " line 38. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(Fr_eq(lvar[1],signalValues[mySignalStart + 253])));
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void LessThan_6_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 6;
ctx->componentMemory[coffset].templateName = "LessThan";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void LessThan_6_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[3];
u64 lvar[1];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
lvar[0] = 252ull;
{
std::string new_cmp_name = "n2b";
Num2Bits_5_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
if (!Fr_isTrue(1ull)) std::cout << "Failed assert in template/function " << myTemplateName << " line 90. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(1ull));
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 253] = Fr_sub(Fr_add(signalValues[mySignalStart + 1],0ull),signalValues[mySignalStart + 2]);
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Num2Bits_5_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
signalValues[mySignalStart + 0] = Fr_sub(1ull,ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 252]);
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void GreaterEqThan_7_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 7;
ctx->componentMemory[coffset].templateName = "GreaterEqThan";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void GreaterEqThan_7_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[2];
u64 lvar[1];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
lvar[0] = 252ull;
{
std::string new_cmp_name = "lt";
LessThan_6_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 2];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = Fr_add(signalValues[mySignalStart + 1],1ull);
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessThan_6_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
signalValues[mySignalStart + 0] = ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0];
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void MultiMux1_8_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 8;
ctx->componentMemory[coffset].templateName = "MultiMux1";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 3;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void MultiMux1_8_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[3];
u64 lvar[2];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
lvar[0] = 1ull;
// load src
// end load src
lvar[1] = 0ull;
while(Fr_isTrue(Fr_lt(lvar[1],1ull))){
// load src
// end load src
signalValues[mySignalStart + 0] = Fr_add(Fr_mul(Fr_sub(signalValues[mySignalStart + 2],signalValues[mySignalStart + 1]),signalValues[mySignalStart + 3]),signalValues[mySignalStart + 1]);
// load src
// end load src
lvar[1] = 1ull;
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void Mux1_9_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 9;
ctx->componentMemory[coffset].templateName = "Mux1";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 3;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void Mux1_9_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[2];
u64 lvar[1];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
std::string new_cmp_name = "mux";
MultiMux1_8_create(mySignalStart+4,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
// load src
// end load src
lvar[0] = 0ull;
// load src
// end load src
lvar[0] = 0ull;
while(Fr_isTrue(Fr_lt(lvar[0],2ull))){
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((0 + (1 * Fr_toInt(lvar[0]))) + 1)] = signalValues[mySignalStart + ((1 * Fr_toInt(lvar[0])) + 1)];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
// load src
// end load src
lvar[0] = Fr_add(lvar[0],1ull);
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = signalValues[mySignalStart + 3];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
MultiMux1_8_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
signalValues[mySignalStart + 0] = ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0];
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void GreaterThan_10_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 10;
ctx->componentMemory[coffset].templateName = "GreaterThan";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void GreaterThan_10_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[1];
u64 lvar[1];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
lvar[0] = 252ull;
{
std::string new_cmp_name = "lt";
LessThan_6_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 2];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 1];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessThan_6_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
signalValues[mySignalStart + 0] = ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0];
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void main_template_11_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 11;
ctx->componentMemory[coffset].templateName = "main_template";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 0;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[56]{0};
main_template_11_run(coffset,ctx);
}

void main_template_11_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[3];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
std::string new_cmp_name = "comp_0";
NOT_0_create(mySignalStart+36,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
std::string new_cmp_name = "comp_1";
NOT_0_create(mySignalStart+38,1+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[1] = 1+ctx_index+1;
}
{
std::string new_cmp_name = "comp_2";
OR_1_create(mySignalStart+830,14+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[2] = 14+ctx_index+1;
}
{
std::string new_cmp_name = "comp_3";
AND_2_create(mySignalStart+1123,27+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[3] = 27+ctx_index+1;
}
{
std::string new_cmp_name = "comp_7";
IsEqual_4_create(mySignalStart+1987,64+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[4] = 64+ctx_index+1;
}
{
std::string new_cmp_name = "comp_10";
LessThan_6_create(mySignalStart+40,2+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[5] = 2+ctx_index+1;
}
{
std::string new_cmp_name = "comp_11";
OR_1_create(mySignalStart+297,4+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[6] = 4+ctx_index+1;
}
{
std::string new_cmp_name = "comp_14";
GreaterEqThan_7_create(mySignalStart+300,5+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[7] = 5+ctx_index+1;
}
{
std::string new_cmp_name = "comp_15";
Mux1_9_create(mySignalStart+560,8+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[8] = 8+ctx_index+1;
}
{
std::string new_cmp_name = "comp_18";
GreaterThan_10_create(mySignalStart+568,10+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[9] = 10+ctx_index+1;
}
{
std::string new_cmp_name = "comp_19";
NOT_0_create(mySignalStart+828,13+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[10] = 13+ctx_index+1;
}
{
std::string new_cmp_name = "comp_20";
AND_2_create(mySignalStart+833,15+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[11] = 15+ctx_index+1;
}
{
std::string new_cmp_name = "comp_21";
NOT_0_create(mySignalStart+836,16+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[12] = 16+ctx_index+1;
}
{
std::string new_cmp_name = "comp_22";
AND_2_create(mySignalStart+838,17+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[13] = 17+ctx_index+1;
}
{
std::string new_cmp_name = "comp_23";
AND_2_create(mySignalStart+841,18+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[14] = 18+ctx_index+1;
}
{
std::string new_cmp_name = "comp_24";
OR_1_create(mySignalStart+844,19+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[15] = 19+ctx_index+1;
}
{
std::string new_cmp_name = "comp_25";
Mux1_9_create(mySignalStart+847,20+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[16] = 20+ctx_index+1;
}
{
std::string new_cmp_name = "comp_28";
GreaterEqThan_7_create(mySignalStart+855,22+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[17] = 22+ctx_index+1;
}
{
std::string new_cmp_name = "comp_29";
Mux1_9_create(mySignalStart+1115,25+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[18] = 25+ctx_index+1;
}
{
std::string new_cmp_name = "comp_31";
Mux1_9_create(mySignalStart+1126,28+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[19] = 28+ctx_index+1;
}
{
std::string new_cmp_name = "comp_37";
Mux1_9_create(mySignalStart+1134,30+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[20] = 30+ctx_index+1;
}
{
std::string new_cmp_name = "comp_38";
Mux1_9_create(mySignalStart+1142,32+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[21] = 32+ctx_index+1;
}
{
std::string new_cmp_name = "comp_39";
NOT_0_create(mySignalStart+1150,34+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[22] = 34+ctx_index+1;
}
{
std::string new_cmp_name = "comp_40";
NOT_0_create(mySignalStart+1152,35+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[23] = 35+ctx_index+1;
}
{
std::string new_cmp_name = "comp_41";
NOT_0_create(mySignalStart+1154,36+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[24] = 36+ctx_index+1;
}
{
std::string new_cmp_name = "comp_42";
NOT_0_create(mySignalStart+1156,37+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[25] = 37+ctx_index+1;
}
{
std::string new_cmp_name = "comp_43";
NOT_0_create(mySignalStart+1158,38+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[26] = 38+ctx_index+1;
}
{
std::string new_cmp_name = "comp_44";
AND_2_create(mySignalStart+1160,39+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[27] = 39+ctx_index+1;
}
{
std::string new_cmp_name = "comp_45";
NOT_0_create(mySignalStart+1163,40+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[28] = 40+ctx_index+1;
}
{
std::string new_cmp_name = "comp_46";
AND_2_create(mySignalStart+1165,41+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[29] = 41+ctx_index+1;
}
{
std::string new_cmp_name = "comp_47";
OR_1_create(mySignalStart+1168,42+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[30] = 42+ctx_index+1;
}
{
std::string new_cmp_name = "comp_48";
OR_1_create(mySignalStart+1171,43+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[31] = 43+ctx_index+1;
}
{
std::string new_cmp_name = "comp_49";
AND_2_create(mySignalStart+1174,44+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[32] = 44+ctx_index+1;
}
{
std::string new_cmp_name = "comp_52";
IsEqual_4_create(mySignalStart+1177,45+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[33] = 45+ctx_index+1;
}
{
std::string new_cmp_name = "comp_55";
LessThan_6_create(mySignalStart+1183,47+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[34] = 47+ctx_index+1;
}
{
std::string new_cmp_name = "comp_56";
OR_1_create(mySignalStart+1440,49+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[35] = 49+ctx_index+1;
}
{
std::string new_cmp_name = "comp_59";
GreaterEqThan_7_create(mySignalStart+1443,50+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[36] = 50+ctx_index+1;
}
{
std::string new_cmp_name = "comp_60";
Mux1_9_create(mySignalStart+1703,53+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[37] = 53+ctx_index+1;
}
{
std::string new_cmp_name = "comp_63";
GreaterThan_10_create(mySignalStart+1711,55+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[38] = 55+ctx_index+1;
}
{
std::string new_cmp_name = "comp_64";
OR_1_create(mySignalStart+1971,58+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[39] = 58+ctx_index+1;
}
{
std::string new_cmp_name = "comp_65";
NOT_0_create(mySignalStart+1974,59+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[40] = 59+ctx_index+1;
}
{
std::string new_cmp_name = "comp_66";
AND_2_create(mySignalStart+1976,60+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[41] = 60+ctx_index+1;
}
{
std::string new_cmp_name = "comp_67";
AND_2_create(mySignalStart+1979,61+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[42] = 61+ctx_index+1;
}
{
std::string new_cmp_name = "comp_68";
OR_1_create(mySignalStart+1982,62+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[43] = 62+ctx_index+1;
}
{
std::string new_cmp_name = "comp_69";
NOT_0_create(mySignalStart+1985,63+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[44] = 63+ctx_index+1;
}
{
std::string new_cmp_name = "comp_70";
AND_2_create(mySignalStart+1993,66+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[45] = 66+ctx_index+1;
}
{
std::string new_cmp_name = "comp_71";
OR_1_create(mySignalStart+1996,67+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[46] = 67+ctx_index+1;
}
{
std::string new_cmp_name = "comp_72";
AND_2_create(mySignalStart+1999,68+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[47] = 68+ctx_index+1;
}
{
std::string new_cmp_name = "comp_73";
Mux1_9_create(mySignalStart+2002,69+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[48] = 69+ctx_index+1;
}
{
std::string new_cmp_name = "comp_76";
GreaterThan_10_create(mySignalStart+2010,71+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[49] = 71+ctx_index+1;
}
{
std::string new_cmp_name = "comp_79";
IsEqual_4_create(mySignalStart+2270,74+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[50] = 74+ctx_index+1;
}
{
std::string new_cmp_name = "comp_80";
OR_1_create(mySignalStart+2276,76+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[51] = 76+ctx_index+1;
}
{
std::string new_cmp_name = "comp_81";
Mux1_9_create(mySignalStart+2279,77+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[52] = 77+ctx_index+1;
}
{
std::string new_cmp_name = "comp_84";
Mux1_9_create(mySignalStart+2287,79+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[53] = 79+ctx_index+1;
}
{
std::string new_cmp_name = "comp_88";
Mux1_9_create(mySignalStart+2295,81+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[54] = 81+ctx_index+1;
}
{
std::string new_cmp_name = "comp_89";
Mux1_9_create(mySignalStart+2303,83+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[55] = 83+ctx_index+1;
}
{
if (!Fr_isTrue(1ull)) std::cout << "Failed assert in template/function " << myTemplateName << " line 11. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(1ull));
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 1;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 2;
// load src
cmp_index_ref_load = 1;
cmp_index_ref_load = 1;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 2;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 3;
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 3;
// load src
cmp_index_ref_load = 2;
cmp_index_ref_load = 2;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_2_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 1] = 0ull;
// load src
// end load src
signalValues[mySignalStart + 2] = Fr_neg(Fr_add(1ull,signalValues[mySignalStart + 1]));
// load src
// end load src
signalValues[mySignalStart + 3] = 13705565844730957219ull;
{
uint cmp_index_ref = 4;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 2];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 4;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 3];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_4_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 4] = 13705565844730957219ull;
// load src
// end load src
signalValues[mySignalStart + 5] = 18446744069414584320ull;
{
uint cmp_index_ref = 5;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 4];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 5;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 5];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessThan_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 6;
// load src
cmp_index_ref_load = 4;
cmp_index_ref_load = 4;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[4]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 6;
// load src
cmp_index_ref_load = 5;
cmp_index_ref_load = 5;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[5]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_1_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 6] = 11397571330424374417ull;
// load src
// end load src
signalValues[mySignalStart + 7] = 0ull;
{
uint cmp_index_ref = 7;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 6];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 7;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 7];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
GreaterEqThan_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 8;
// load src
cmp_index_ref_load = 7;
cmp_index_ref_load = 7;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[7]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 8;
// load src
cmp_index_ref_load = 6;
cmp_index_ref_load = 6;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[6]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 8;
// load src
cmp_index_ref_load = 3;
cmp_index_ref_load = 3;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[3]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 8] = 4962951859171512079ull;
// load src
// end load src
signalValues[mySignalStart + 9] = 2412661776526444922ull;
{
uint cmp_index_ref = 9;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 9];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 9;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 8];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
GreaterThan_10_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 10;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 11;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 0ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 11;
// load src
cmp_index_ref_load = 10;
cmp_index_ref_load = 10;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[10]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 12;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 13;
// load src
cmp_index_ref_load = 12;
cmp_index_ref_load = 12;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[12]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 13;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 14;
// load src
cmp_index_ref_load = 13;
cmp_index_ref_load = 13;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[13]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 14;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 15;
// load src
cmp_index_ref_load = 11;
cmp_index_ref_load = 11;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[11]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 15;
// load src
cmp_index_ref_load = 14;
cmp_index_ref_load = 14;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[14]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 16;
// load src
cmp_index_ref_load = 15;
cmp_index_ref_load = 15;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[15]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 16;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 0ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 16;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 10] = 18232007087912405432ull;
// load src
// end load src
signalValues[mySignalStart + 11] = 13571593676252429836ull;
{
uint cmp_index_ref = 17;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 10];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 17;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 11];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
GreaterEqThan_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 18;
// load src
cmp_index_ref_load = 17;
cmp_index_ref_load = 17;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[17]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 18;
// load src
cmp_index_ref_load = 16;
cmp_index_ref_load = 16;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[16]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 18;
// load src
cmp_index_ref_load = 9;
cmp_index_ref_load = 9;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[9]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 12] = 0ull;
{
uint cmp_index_ref = 19;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 12];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 19;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 6628155327940662486ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 19;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 13] = 0ull;
{
if (!Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + 13],1ull),0ull))) std::cout << "Failed assert in template/function " << myTemplateName << " line 98. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + 13],1ull),0ull)));
}
// load src
// end load src
signalValues[mySignalStart + 14] = Fr_bxor(signalValues[mySignalStart + 13],229689663414455172ull);
// load src
cmp_index_ref_load = 19;
cmp_index_ref_load = 19;
// end load src
signalValues[mySignalStart + 15] = Fr_mod(ctx->signalValues[ctx->componentMemory[mySubcomponents[19]].signalStart + 0],signalValues[mySignalStart + 14]);
// load src
// end load src
signalValues[mySignalStart + 16] = 4788009108274200227ull;
// load src
// end load src
signalValues[mySignalStart + 17] = Fr_band(13658734961140384094ull,Fr_neg(signalValues[mySignalStart + 16]));
{
uint cmp_index_ref = 20;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = Fr_add(1ull,signalValues[mySignalStart + 17]);
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 20;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 15];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 20;
// load src
cmp_index_ref_load = 18;
cmp_index_ref_load = 18;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[18]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 21;
// load src
cmp_index_ref_load = 20;
cmp_index_ref_load = 20;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[20]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 21;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 14232881950053995437ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 21;
// load src
cmp_index_ref_load = 8;
cmp_index_ref_load = 8;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[8]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 22;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 23;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 24;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 25;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 26;
// load src
cmp_index_ref_load = 25;
cmp_index_ref_load = 25;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[25]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 27;
// load src
cmp_index_ref_load = 24;
cmp_index_ref_load = 24;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[24]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 27;
// load src
cmp_index_ref_load = 26;
cmp_index_ref_load = 26;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[26]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 28;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 29;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 29;
// load src
cmp_index_ref_load = 28;
cmp_index_ref_load = 28;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[28]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 30;
// load src
cmp_index_ref_load = 27;
cmp_index_ref_load = 27;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[27]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 30;
// load src
cmp_index_ref_load = 29;
cmp_index_ref_load = 29;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[29]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 31;
// load src
cmp_index_ref_load = 23;
cmp_index_ref_load = 23;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[23]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 31;
// load src
cmp_index_ref_load = 30;
cmp_index_ref_load = 30;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[30]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 32;
// load src
cmp_index_ref_load = 22;
cmp_index_ref_load = 22;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[22]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 32;
// load src
cmp_index_ref_load = 31;
cmp_index_ref_load = 31;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[31]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_2_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 18] = 18446744069414584320ull;
// load src
// end load src
signalValues[mySignalStart + 19] = 13705565844730957219ull;
{
uint cmp_index_ref = 33;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 18];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 33;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 19];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_4_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 20] = 13705565844730957219ull;
// load src
// end load src
signalValues[mySignalStart + 21] = 18446744069414584320ull;
{
uint cmp_index_ref = 34;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 20];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 34;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 21];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessThan_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 35;
// load src
cmp_index_ref_load = 33;
cmp_index_ref_load = 33;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[33]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 35;
// load src
cmp_index_ref_load = 34;
cmp_index_ref_load = 34;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[34]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_1_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 22] = 11397571330424374417ull;
// load src
// end load src
signalValues[mySignalStart + 23] = 0ull;
{
uint cmp_index_ref = 36;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 22];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 36;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 23];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
GreaterEqThan_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 37;
// load src
cmp_index_ref_load = 36;
cmp_index_ref_load = 36;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[36]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 37;
// load src
cmp_index_ref_load = 35;
cmp_index_ref_load = 35;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[35]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 37;
// load src
cmp_index_ref_load = 32;
cmp_index_ref_load = 32;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[32]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 24] = 4962951859171512079ull;
// load src
// end load src
signalValues[mySignalStart + 25] = 2412661776526444922ull;
{
uint cmp_index_ref = 38;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 25];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 38;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 24];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
GreaterThan_10_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 39;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 0ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 39;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 40;
// load src
cmp_index_ref_load = 39;
cmp_index_ref_load = 39;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[39]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 41;
// load src
cmp_index_ref_load = 40;
cmp_index_ref_load = 40;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[40]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 41;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 42;
// load src
cmp_index_ref_load = 41;
cmp_index_ref_load = 41;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[41]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 42;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 43;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 0ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 43;
// load src
cmp_index_ref_load = 42;
cmp_index_ref_load = 42;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[42]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 44;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 45;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 0ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 45;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 46;
// load src
cmp_index_ref_load = 44;
cmp_index_ref_load = 44;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[44]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 46;
// load src
cmp_index_ref_load = 45;
cmp_index_ref_load = 45;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[45]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 47;
// load src
cmp_index_ref_load = 43;
cmp_index_ref_load = 43;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[43]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 47;
// load src
cmp_index_ref_load = 46;
cmp_index_ref_load = 46;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[46]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 48;
// load src
cmp_index_ref_load = 47;
cmp_index_ref_load = 47;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[47]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 48;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 0ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 48;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 26] = 18232007087912405432ull;
// load src
// end load src
signalValues[mySignalStart + 27] = 13571593676252429836ull;
{
uint cmp_index_ref = 49;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 26];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 49;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 27];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
GreaterThan_10_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 28] = 18232007087912405432ull;
// load src
// end load src
signalValues[mySignalStart + 29] = 13571593676252429836ull;
{
uint cmp_index_ref = 50;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 28];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 50;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 29];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_4_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 51;
// load src
cmp_index_ref_load = 49;
cmp_index_ref_load = 49;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[49]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 51;
// load src
cmp_index_ref_load = 50;
cmp_index_ref_load = 50;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[50]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 52;
// load src
cmp_index_ref_load = 51;
cmp_index_ref_load = 51;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[51]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 52;
// load src
cmp_index_ref_load = 48;
cmp_index_ref_load = 48;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[48]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 52;
// load src
cmp_index_ref_load = 38;
cmp_index_ref_load = 38;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[38]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 30] = 0ull;
// load src
// end load src
signalValues[mySignalStart + 31] = Fr_bor(signalValues[mySignalStart + 30],0ull);
{
uint cmp_index_ref = 53;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 31];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 53;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 6628155327940662486ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 53;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 32] = 229689663414455172ull;
// load src
cmp_index_ref_load = 53;
cmp_index_ref_load = 53;
// end load src
signalValues[mySignalStart + 33] = Fr_mod(ctx->signalValues[ctx->componentMemory[mySubcomponents[53]].signalStart + 0],signalValues[mySignalStart + 32]);
// load src
// end load src
signalValues[mySignalStart + 34] = 13658734961140384094ull;
{
uint cmp_index_ref = 54;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = Fr_add(1ull,signalValues[mySignalStart + 34]);
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 54;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 33];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 54;
// load src
cmp_index_ref_load = 52;
cmp_index_ref_load = 52;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[52]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 55;
// load src
cmp_index_ref_load = 54;
cmp_index_ref_load = 54;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[54]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 55;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 14232881950053995437ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 55;
// load src
cmp_index_ref_load = 37;
cmp_index_ref_load = 37;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[37]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 21;
cmp_index_ref_load = 21;
cmp_index_ref_load = 55;
cmp_index_ref_load = 55;
// end load src
signalValues[mySignalStart + 35] = Fr_band(ctx->signalValues[ctx->componentMemory[mySubcomponents[21]].signalStart + 0],ctx->signalValues[ctx->componentMemory[mySubcomponents[55]].signalStart + 0]);
// load src
// end load src
signalValues[mySignalStart + 0] = signalValues[mySignalStart + 35];
{
printf("<@> out0 = ");
}
{
printf(" ");
}
{
char* temp = Fr_element2str(signalValues[mySignalStart + 0]);
printf("%s",temp);
delete [] temp;
}
{
printf("\n");
}
for (uint i = 0; i < 56; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void run(Circom_CalcWit* ctx){
main_template_11_create(1,0,ctx,"main",0);
// no input signals, the creation will automatically execute
}

