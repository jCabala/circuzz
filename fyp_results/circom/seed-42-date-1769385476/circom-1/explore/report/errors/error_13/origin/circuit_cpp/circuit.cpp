#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
#include "fr.hpp"
void Num2Bits_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Num2Bits_0_run(uint ctx_index,Circom_CalcWit* ctx);
void LessThan_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void LessThan_1_run(uint ctx_index,Circom_CalcWit* ctx);
void LessEqThan_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void LessEqThan_2_run(uint ctx_index,Circom_CalcWit* ctx);
void IsZero_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsZero_3_run(uint ctx_index,Circom_CalcWit* ctx);
void IsEqual_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsEqual_4_run(uint ctx_index,Circom_CalcWit* ctx);
void OR_5_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void OR_5_run(uint ctx_index,Circom_CalcWit* ctx);
void MultiMux1_6_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiMux1_6_run(uint ctx_index,Circom_CalcWit* ctx);
void Mux1_7_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Mux1_7_run(uint ctx_index,Circom_CalcWit* ctx);
void main_template_8_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void main_template_8_run(uint ctx_index,Circom_CalcWit* ctx);
Circom_TemplateFunction _functionTable[9] = { 
Num2Bits_0_run,
LessThan_1_run,
LessEqThan_2_run,
IsZero_3_run,
IsEqual_4_run,
OR_5_run,
MultiMux1_6_run,
Mux1_7_run,
main_template_8_run };
Circom_TemplateFunction _functionTableParallel[9] = { 
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

uint get_total_signal_no() {return 284;}

uint get_number_of_components() {return 9;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 253;}

uint get_size_of_constants() {return 12;}

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
void Num2Bits_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "Num2Bits";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void Num2Bits_0_run(uint ctx_index,Circom_CalcWit* ctx){
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

void LessThan_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 1;
ctx->componentMemory[coffset].templateName = "LessThan";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void LessThan_1_run(uint ctx_index,Circom_CalcWit* ctx){
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
Num2Bits_0_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
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
Num2Bits_0_run(mySubcomponents[cmp_index_ref],ctx);
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

void LessEqThan_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 2;
ctx->componentMemory[coffset].templateName = "LessEqThan";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void LessEqThan_2_run(uint ctx_index,Circom_CalcWit* ctx){
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
LessThan_1_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 1];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = Fr_add(signalValues[mySignalStart + 2],1ull);
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessThan_1_run(mySubcomponents[cmp_index_ref],ctx);
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

void OR_5_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 5;
ctx->componentMemory[coffset].templateName = "OR";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void OR_5_run(uint ctx_index,Circom_CalcWit* ctx){
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

void MultiMux1_6_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 6;
ctx->componentMemory[coffset].templateName = "MultiMux1";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 3;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void MultiMux1_6_run(uint ctx_index,Circom_CalcWit* ctx){
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

void Mux1_7_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 7;
ctx->componentMemory[coffset].templateName = "Mux1";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 3;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void Mux1_7_run(uint ctx_index,Circom_CalcWit* ctx){
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
MultiMux1_6_create(mySignalStart+4,0+ctx_index+1,ctx,new_cmp_name,myId);
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
MultiMux1_6_run(mySubcomponents[cmp_index_ref],ctx);
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

void main_template_8_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 8;
ctx->componentMemory[coffset].templateName = "main_template";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 0;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[4]{0};
main_template_8_run(coffset,ctx);
}

void main_template_8_run(uint ctx_index,Circom_CalcWit* ctx){
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
std::string new_cmp_name = "comp_2";
LessEqThan_2_create(mySignalStart+6,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
std::string new_cmp_name = "comp_5";
IsEqual_4_create(mySignalStart+266,3+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[1] = 3+ctx_index+1;
}
{
std::string new_cmp_name = "comp_6";
OR_5_create(mySignalStart+272,5+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[2] = 5+ctx_index+1;
}
{
std::string new_cmp_name = "comp_7";
Mux1_7_create(mySignalStart+275,6+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[3] = 6+ctx_index+1;
}
// load src
// end load src
signalValues[mySignalStart + 1] = 1890430877123251293ull;
// load src
// end load src
signalValues[mySignalStart + 2] = 10017450089846787151ull;
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 1];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 2];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessEqThan_2_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 3] = 5046601652994418491ull;
// load src
// end load src
signalValues[mySignalStart + 4] = 1678708292792433268ull;
{
uint cmp_index_ref = 1;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 3];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 1;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 4];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_4_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 2;
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
uint cmp_index_ref = 2;
// load src
cmp_index_ref_load = 1;
cmp_index_ref_load = 1;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 3;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 11450900877433446404ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 3;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 11047023035607765551ull;
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
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_7_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 3;
cmp_index_ref_load = 3;
// end load src
signalValues[mySignalStart + 5] = Fr_div(ctx->signalValues[ctx->componentMemory[mySubcomponents[3]].signalStart + 0],15583005803237895103ull);
{
cmp_index_ref_load = 3;
cmp_index_ref_load = 3;
if (!Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + 5],15583005803237895103ull),ctx->signalValues[ctx->componentMemory[mySubcomponents[3]].signalStart + 0]))) std::cout << "Failed assert in template/function " << myTemplateName << " line 34. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + 5],15583005803237895103ull),ctx->signalValues[ctx->componentMemory[mySubcomponents[3]].signalStart + 0])));
}
// load src
// end load src
signalValues[mySignalStart + 0] = signalValues[mySignalStart + 5];
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
for (uint i = 0; i < 4; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void run(Circom_CalcWit* ctx){
main_template_8_create(1,0,ctx,"main",0);
// no input signals, the creation will automatically execute
}

